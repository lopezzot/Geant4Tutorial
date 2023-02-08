//**************************************************
// \file NeutrinoConstructor.cc
// \brief: Definition of NeutrinoConstructor class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 13 December 2022
//**************************************************

#include "NeutrinoConstructor.hh"

#include "G4AntiNeutrinoE.hh"
#include "G4AntiNeutrinoMu.hh"
#include "G4AntiNeutrinoTau.hh"
#include "G4NeutrinoE.hh"
#include "G4NeutrinoMu.hh"
#include "G4NeutrinoTau.hh"

#include "G4NeutrinoElectronCcModel.hh"
#include "G4NeutrinoElectronNcModel.hh"
#include "G4NeutrinoElectronProcess.hh"
#include "G4NeutrinoElectronTotXsc.hh"
#include "G4PhysicsListHelper.hh"

#include "G4ANuElNucleusCcModel.hh"
#include "G4ANuElNucleusNcModel.hh"
#include "G4ElNeutrinoNucleusProcess.hh"
#include "G4ElNeutrinoNucleusTotXsc.hh"
#include "G4NuElNucleusCcModel.hh"
#include "G4NuElNucleusNcModel.hh"

NeutrinoConstructor::NeutrinoConstructor(G4int ver) {
  if (ver > 0) {
    G4cout << "--> Registering user NeutrincoConstructor" << G4endl;
  }
}

NeutrinoConstructor::~NeutrinoConstructor() {}

void NeutrinoConstructor::ConstructParticle() {

  G4AntiNeutrinoE::AntiNeutrinoE();
  G4NeutrinoE::NeutrinoE();
  G4AntiNeutrinoMu::AntiNeutrinoMu();
  G4NeutrinoMu::NeutrinoMu();
  G4AntiNeutrinoTau::AntiNeutrinoTau();
  G4NeutrinoTau::NeutrinoTau();
}

void NeutrinoConstructor::ConstructProcess() {

  G4PhysicsListHelper *ph = G4PhysicsListHelper::GetPhysicsListHelper();

  G4ParticleDefinition *anuelectron = G4AntiNeutrinoE::AntiNeutrinoE();
  G4ParticleDefinition *nuelectron = G4NeutrinoE::NeutrinoE();
  G4ParticleDefinition *anumuon = G4AntiNeutrinoMu::AntiNeutrinoMu();
  G4ParticleDefinition *numuon = G4NeutrinoMu::NeutrinoMu();
  G4ParticleDefinition *anutau = G4AntiNeutrinoTau::AntiNeutrinoTau();
  G4ParticleDefinition *nutau = G4NeutrinoTau::NeutrinoTau();

  G4NeutrinoElectronProcess *theNuEleProcess =
      new G4NeutrinoElectronProcess("neutrinoRegion");
  G4NeutrinoElectronTotXsc *theNuEleTotXsc = new G4NeutrinoElectronTotXsc();

  // biasing
  //
  theNuEleProcess->SetBiasingFactor(1e20);
  theNuEleProcess->SetBiasingFactors(1e20, 1e20);
  theNuEleTotXsc->SetBiasingFactors(1e20, 1e20);

  theNuEleProcess->AddDataSet(theNuEleTotXsc);

  G4NeutrinoElectronCcModel *ccModel = new G4NeutrinoElectronCcModel();
  G4NeutrinoElectronNcModel *ncModel = new G4NeutrinoElectronNcModel();
  theNuEleProcess->RegisterMe(ccModel);
  theNuEleProcess->RegisterMe(ncModel);
  /*
      ph->RegisterProcess(theNuEleProcess, anuelectron);
      ph->RegisterProcess(theNuEleProcess, nuelectron);
      ph->RegisterProcess(theNuEleProcess, anumuon);
      ph->RegisterProcess(theNuEleProcess, numuon);
      ph->RegisterProcess(theNuEleProcess, anutau);
      ph->RegisterProcess(theNuEleProcess, nutau);
  */
  /*
  // nu_mu nucleus interactions

  G4MuNeutrinoNucleusProcess* theNuMuNucleusProcess = new
  G4MuNeutrinoNucleusProcess(fNuDetectorName); G4MuNeutrinoNucleusTotXsc*
  theNuMuNucleusTotXsc = new G4MuNeutrinoNucleusTotXsc();

  if(fNuETotXscActivated)
  {
    theNuMuNucleusProcess->SetBiasingFactor(fNuNucleusBias);
  }
  theNuMuNucleusProcess->AddDataSet(theNuMuNucleusTotXsc);

  G4NuMuNucleusCcModel* numunuclcc = new G4NuMuNucleusCcModel();
  G4NuMuNucleusNcModel* numunuclnc = new G4NuMuNucleusNcModel();
  G4ANuMuNucleusCcModel* anumunuclcc = new G4ANuMuNucleusCcModel();
  G4ANuMuNucleusNcModel* anumunuclnc = new G4ANuMuNucleusNcModel();

  theNuMuNucleusProcess->RegisterMe(numunuclcc);
  theNuMuNucleusProcess->RegisterMe(numunuclnc);
  theNuMuNucleusProcess->RegisterMe(anumunuclcc);
  theNuMuNucleusProcess->RegisterMe(anumunuclnc);

  ph->RegisterProcess(theNuMuNucleusProcess, anumuon);
  ph->RegisterProcess(theNuMuNucleusProcess, numuon);
  */

  // nu_e nucleus interactions
  //
  G4ElNeutrinoNucleusProcess *theNuElNucleusProcess =
      new G4ElNeutrinoNucleusProcess("neutrinoRegion");
  G4ElNeutrinoNucleusTotXsc *theNuElNucleusTotXsc =
      new G4ElNeutrinoNucleusTotXsc();

  theNuElNucleusProcess->SetBiasingFactor(1e20);
  theNuElNucleusProcess->AddDataSet(theNuElNucleusTotXsc);

  G4NuElNucleusCcModel *nuelnuclcc = new G4NuElNucleusCcModel();
  G4NuElNucleusNcModel *nuelnuclnc = new G4NuElNucleusNcModel();
  G4ANuElNucleusCcModel *anuelnuclcc = new G4ANuElNucleusCcModel();
  G4ANuElNucleusNcModel *anuelnuclnc = new G4ANuElNucleusNcModel();

  theNuElNucleusProcess->RegisterMe(nuelnuclcc);
  theNuElNucleusProcess->RegisterMe(nuelnuclnc);
  theNuElNucleusProcess->RegisterMe(anuelnuclcc);
  theNuElNucleusProcess->RegisterMe(anuelnuclnc);

  ph->RegisterProcess(theNuElNucleusProcess, anuelectron);
  ph->RegisterProcess(theNuElNucleusProcess, nuelectron);
}

//**************************************************
