//**************************************************
// \file BiasPhysics.cc
// \brief: implementation of BiasPhysics class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 27 October 2023
//**************************************************

// Includers from project files
//
#include "BiasPhysics.hh"

// Includers from Geant4
//
#include "G4DeexPrecoParameters.hh"
#include "G4EmParameters.hh"
#include "G4GenericIon.hh"
#include "G4HadronicProcess.hh"
#include "G4LossTableManager.hh"
#include "G4MuonMinus.hh"
#include "G4NuclearLevelData.hh"
#include "G4NuclideTable.hh"
#include "G4PhysicsListHelper.hh"
#include "G4ProcessManager.hh"
#include "G4ProcessVector.hh"
#include "G4Radioactivation.hh"
#include "G4SystemOfUnits.hh"
#include "G4UAtomicDeexcitation.hh"
#include "G4VAtomDeexcitation.hh"

BiasPhysics::BiasPhysics() : G4VPhysicsConstructor() {}

BiasPhysics::~BiasPhysics() {}

void BiasPhysics::ConstructParticle() {}

void BiasPhysics::ConstructProcess()
{
  G4HadronicProcess* muInelasticProcess = nullptr;
  G4ProcessVector* pvec = G4MuonMinus::MuonMinus()->GetProcessManager()->GetProcessList();
  for (std::size_t i = 0; i < pvec->size(); i++) {
    if ((*pvec)[i]->GetProcessName() == "muonNuclear") {
      muInelasticProcess = static_cast<G4HadronicProcess*>((*pvec)[i]);
      break;
    }
  }
  if (muInelasticProcess) {
    muInelasticProcess->BiasCrossSectionByFactor(1e7);
  }
}

//**************************************************
