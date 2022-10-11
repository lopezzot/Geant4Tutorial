//**************************************************
// \file PhysicsList.cc
// \brief: main() of PhysicsList tutorial
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 10 October 2022
//**************************************************

//Includers from project files
//
#include "PLDetectorConstruction.hh"
#include "PLActionInitialization.hh"
#include "PLUser.hh"

//Includers from Geant4
//
#include "G4RunManagerFactory.hh"
#include "QBBC.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4VisExecutive.hh"

int main(int argc,char** argv) {

    //Set user interface
    //
    G4UIExecutive* ui = nullptr;
    if ( argc == 1 ) { ui = new G4UIExecutive(argc, argv); }
    //Initialize visualization
    //
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();
    //Get the pointer to the User Interface manager
    //
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    //Construct the default run manager
    //
    auto* runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);

    //Set mandatory initialization classes
    //
    //Detector constructioin and action initialization
    //
    runManager->SetUserInitialization(new PLDetectorConstruction());
    runManager->SetUserInitialization(new PLActionInitialization());

    // Physics list
    //G4VModularPhysicsList* physicsList = new QBBC;
    //physicsList->SetVerboseLevel(1);
    runManager->SetUserInitialization(new PLUser);
    
    //Process macro or start UI session
    //
    if ( ! ui ) {
        //batch mode
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command+fileName);
    }
    else {
        //interactive mode
        UImanager->ApplyCommand("/control/execute init_vis.mac");
        ui->SessionStart();
        delete ui;
    }
    
    delete visManager;
    delete runManager;

}

//**************************************************
