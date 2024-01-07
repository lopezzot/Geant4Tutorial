//**************************************************
// \file RunAction.cc
// \brief: Implementation of RunAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 14 December 2023
//**************************************************

// Includers from project files
//
#include "RunAction.hh"

// Includers from Geant4
//
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4Version.hh"
#if G4VERSION_NUMBER < 1100
#  include "g4root.hh"
#else
#  include "G4AnalysisManager.hh"
#endif
#include <string>

// Define constructor
//
RunAction::RunAction()
  : G4UserRunAction()
{
  G4RunManager::GetRunManager()->SetPrintProgress(1);  // print each event number

  // Instantiate analysis manager
  auto analysisManager = G4AnalysisManager::Instance();  // using ROOT
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetNtupleMerging(1);

  analysisManager->CreateNtuple("output", "output");
  analysisManager->CreateNtupleDColumn("px");
  analysisManager->CreateNtupleDColumn("py");
  analysisManager->FinishNtuple();

}

// Define deconstructor
//
RunAction::~RunAction()
{
#if G4VERSION_NUMBER < 1100
  delete G4AnalysisManager::Instance();  // not needed for G4 v11 and up
#endif
}

// Define BeginOfRunAction() and EndOfRunAction() methods
//
void RunAction::BeginOfRunAction(const G4Run* Run)
{
  // Inform RunManager to save random seeds
  //
  // G4RunManager::GetRunManager()->SetRandomNumberStore( true );

  auto analysisManager = G4AnalysisManager::Instance();

  std::string runnumber = std::to_string(Run->GetRunID());
  G4String outputfile = "Output_Run" + runnumber + ".root";
  analysisManager->OpenFile(outputfile);
}

void RunAction::EndOfRunAction(const G4Run*)
{
  auto analysisManager = G4AnalysisManager::Instance();

  analysisManager->Write();
  analysisManager->CloseFile();
}

//**************************************************
