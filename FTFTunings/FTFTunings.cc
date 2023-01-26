//**************************************************
// \file FTFTunings.cc
// \brief: main() of FTFTunings tutorial
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 25 January 2023
//**************************************************

// Includers from project files
//
#include "ActionInitialization.hh"
#include "DetectorConstruction.hh"

// Includers from Geant4
//
#include "FTFP_BERT.hh"
#include "G4FTFTunings.hh" //this is the class to select "tunes"
#include "G4PionMinus.hh"
#include "G4RunManagerFactory.hh"
#include "G4SystemOfUnits.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"

int main(int argc, char **argv) {

  // Set user interface
  //
  G4UIExecutive *ui = nullptr;
  if (argc == 1) {
    ui = new G4UIExecutive(argc, argv);
  }
  // Initialize visualization
  //
  G4VisManager *visManager = new G4VisExecutive;
  visManager->Initialize();
  // Get the pointer to the User Interface manager
  //
  G4UImanager *UImanager = G4UImanager::GetUIpointer();

  // Construct the default run manager (SERIAL)
  //
  auto *runManager =
      G4RunManagerFactory::CreateRunManager(G4RunManagerType::Serial);

  // Physics list
  //
  G4VModularPhysicsList *physicsList = new FTFP_BERT();
  physicsList->SetVerboseLevel(1);
  runManager->SetUserInitialization(physicsList);

  // This part shows how to use the G4FTFTunings class
  //
  auto FTFTunings = G4FTFTunings::Instance();
  // Print tunes names by index
  //
  G4cout << "Tune name 0: " << FTFTunings->GetTuneName(0) << G4endl;
  G4cout << "Tune name 1: " << FTFTunings->GetTuneName(1) << G4endl;
  G4cout << "Tune name 2: " << FTFTunings->GetTuneName(2) << G4endl;
  G4cout << "Tune name 3: " << FTFTunings->GetTuneName(3) << G4endl;
  G4cout << "Tune name 4: " << FTFTunings->GetTuneName(4) << G4endl;
  // Get tunes applicability state (0 ON, 1 OFF)
  //
  G4cout << "Tune 0 state: " << FTFTunings->GetTuneApplicabilityState(0)
         << G4endl;
  G4cout << "Tune 1 state: " << FTFTunings->GetTuneApplicabilityState(1)
         << G4endl;
  G4cout << "Tune 2 state: " << FTFTunings->GetTuneApplicabilityState(2)
         << G4endl;
  G4cout << "Tune 3 state: " << FTFTunings->GetTuneApplicabilityState(3)
         << G4endl;
  G4cout << "Tune 4 state: " << FTFTunings->GetTuneApplicabilityState(4)
         << G4endl;
  // Set a tune applicability state by index
  // arguments: index, state(0,1)
  //
  FTFTunings->SetTuneApplicabilityState(0, 0); // default
  FTFTunings->SetTuneApplicabilityState(1, 0); // baryon-tune2022-v0
  FTFTunings->SetTuneApplicabilityState(2, 0); // pion-tune2022-v0
  FTFTunings->SetTuneApplicabilityState(3, 1); // combined-tune2022-v0
  // Get index tune: return index of tune (0 for default)
  // given particle definition and energy
  //
  G4cout << "Tune index pi- 100 GeV: "
         << FTFTunings->GetIndexTune(G4PionMinus::PionMinus(), 100000)
         << G4endl;

  // Detector constructioin and action initialization
  //
  runManager->SetUserInitialization(new DetectorConstruction());
  runManager->SetUserInitialization(new ActionInitialization());

  // Process macro or start UI session
  //
  if (!ui) {
    // batch mode
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager->ApplyCommand(command + fileName);
  } else {
    // interactive mode
    UImanager->ApplyCommand("/control/execute init_vis.mac");
    ui->SessionStart();
    delete ui;
  }

  delete visManager;
  delete runManager;
}

//**************************************************
