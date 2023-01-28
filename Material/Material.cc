//**************************************************
// \file Material.cc
// \brief: main() of Material tutorial
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 17 October 2022
//**************************************************

// Includers from project files
//
#include "ActionInitialization.hh"
#include "DetectorConstruction.hh"

// Includers from Geant4
//
#include "FTFP_BERT.hh"
#include "G4PhysListFactory.hh"
#include "G4RunManagerFactory.hh"
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
      G4RunManagerFactory::CreateRunManager(G4RunManagerType::SerialOnly);

  // Physics list
  // Select PL via PLFactory
  //
  // G4PhysListFactory PLFactory;
  // const G4String PLName = "QGSP_BIC_HP_EMY";
  // G4VModularPhysicsList *PL = PLFactory.GetReferencePhysList(PLName);
  // runManager->SetUserInitialization(PL);
  // Or use FTFP_BERT PL
  //
  G4VModularPhysicsList *physicsList = new FTFP_BERT();
  physicsList->SetVerboseLevel(1);
  runManager->SetUserInitialization(physicsList);

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
