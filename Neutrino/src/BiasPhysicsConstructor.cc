//**************************************************
// \file BiasPhysicsConstructor.cc
// \brief: Definition of BiasPhysicsConstructor
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 13 December 2022
//**************************************************

#include "BiasPhysicsConstructor.hh"
#include "G4HadronicProcess.hh"
#include "G4MuonMinus.hh"
#include "G4NeutrinoE.hh"
#include "G4ProcessManager.hh"
#include "G4ProcessVector.hh"

BiasPhysicsConstructor::BiasPhysicsConstructor() : G4VPhysicsConstructor() {}

BiasPhysicsConstructor::~BiasPhysicsConstructor() {}

void BiasPhysicsConstructor::ConstructParticle() {}

void BiasPhysicsConstructor::ConstructProcess() {

  G4HadronicProcess *theNuEleProcess = nullptr;
  G4ProcessVector *pvec =
      G4NeutrinoE::NeutrinoE()->GetProcessManager()->GetProcessList();

  for (std::size_t i = 0; i < pvec->size(); i++) {
    if ((*pvec)[i]->GetProcessName() == "neutrino-electron") {
      theNuEleProcess = static_cast<G4HadronicProcess *>((*pvec)[i]);
      G4cout << "--->BiasPhysicsConstructor: theNuEleProcess found" << G4endl;
      break;
    }
  }
  if (theNuEleProcess) {
    G4cout << "--->BiasPhysicsConstructor: biasing theNuEleProcess XS"
           << G4endl;
    theNuEleProcess->BiasCrossSectionByFactor(1e20);
  }

  G4HadronicProcess *theNuNuclProcess = nullptr;
  // G4ProcessVector* pvec =
  // G4NeutrinoE::NeutrinoE()->GetProcessManager()->GetProcessList();

  for (std::size_t i = 0; i < pvec->size(); i++) {
    if ((*pvec)[i]->GetProcessName() == "mu-neutrino-nucleus") {
      theNuNuclProcess = static_cast<G4HadronicProcess *>((*pvec)[i]);
      G4cout << "--->BiasPhysicsConstructor: theNuNuclProcess found" << G4endl;
      break;
    }
  }
  if (theNuNuclProcess) {
    G4cout << "--->BiasPhysicsConstructor: biasing theNuNuclProcess XS"
           << G4endl;
    theNuNuclProcess->BiasCrossSectionByFactor(1e20);
  }

  G4HadronicProcess *muInelasticProcess = nullptr;
  G4ProcessVector *pvecmu =
      G4MuonMinus::MuonMinus()->GetProcessManager()->GetProcessList();
  for (std::size_t i = 0; i < pvecmu->size(); i++) {
    if ((*pvecmu)[i]->GetProcessName() == "muonNuclear") {
      muInelasticProcess = static_cast<G4HadronicProcess *>((*pvecmu)[i]);
      break;
    }
  }
  if (muInelasticProcess) {
    muInelasticProcess->BiasCrossSectionByFactor(10000000.);
  }
}

//**************************************************
