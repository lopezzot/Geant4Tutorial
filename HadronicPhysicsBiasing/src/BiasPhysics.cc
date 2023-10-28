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
#include "G4HadronicProcess.hh"
#include "G4MuonMinus.hh"
#include "G4ProcessManager.hh"
#include "G4ProcessVector.hh"

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
