//**************************************************
// \file BRunAction.cc
// \brief: implementation of RunAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 24 October 2022
//**************************************************

//Includers from project files
//
#include "RunAction.hh"

//Includers from Geant4
//
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4Version.hh"
#if G4VERSION_NUMBER < 1100
#include "g4root.hh"  // replaced by G4AnalysisManager.h  in G4 v11 and up
#else
#include "G4AnalysisManager.hh"
#endif

RunAction::RunAction()
    : G4UserRunAction() { 
    
    //Get analysis manager
    //
    auto analysisManager = G4AnalysisManager::Instance();

    //Print useful information
    //
    if (IsMaster()) {
        G4cout << "Using " << analysisManager->GetType() << G4endl;
    }

    analysisManager->SetVerboseLevel(1);
    analysisManager->SetNtupleMerging(true);

    // Creating ntuple
    //
    analysisManager->CreateNtuple("Ntuple", "Ntuple");
    analysisManager->CreateNtupleDColumn("Energy");
    analysisManager->CreateNtupleDColumn("Length");
    analysisManager->FinishNtuple();

}

RunAction::~RunAction() {
    #if G4VERSION_NUMBER < 1100
    delete G4AnalysisManager::Instance();  // not needed for G4 v11 and up
    #endif
}

void RunAction::BeginOfRunAction(const G4Run* run) { 
  
    auto analysisManager = G4AnalysisManager::Instance();

    std::string runnumber = std::to_string( run->GetRunID() );
    G4String fileName = "Run" + runnumber + ".root";
    analysisManager->OpenFile(fileName);

}

void RunAction::EndOfRunAction(const G4Run* /*run*/) {

    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();

}

//**************************************************
