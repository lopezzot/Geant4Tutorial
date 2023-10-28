//**************************************************
// \file RunAction.cc
// \brief: implementation of RunAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 24 October 2022
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
#  include "g4root.hh"  // replaced by G4AnalysisManager.h  in G4 v11 and up
#else
#  include "G4AnalysisManager.hh"
#endif

RunAction::RunAction() : G4UserRunAction()
{
  // Get analysis manager
  //
  auto analysisManager = G4AnalysisManager::Instance();

  analysisManager->SetVerboseLevel(1);
  analysisManager->SetNtupleMerging(true);
}

RunAction::~RunAction()
{
#if G4VERSION_NUMBER < 1100
  delete G4AnalysisManager::Instance();  // not needed for G4 v11 and up
#endif
}

void RunAction::BeginOfRunAction(const G4Run* run)
{
  auto analysisManager = G4AnalysisManager::Instance();

  std::string runnumber = std::to_string(run->GetRunID());
  G4String fileName = "Run" + runnumber + ".root";  // root format
  // G4String fileName = "Run" + runnumber + ".xml"; //xml format
  // G4String fileName = "Run" + runnumber + ".csv"; //csv format
  analysisManager->OpenFile(fileName);

  // Print useful information
  //
  if (IsMaster()) {
    G4cout << "Using " << analysisManager->GetType() << G4endl;
    // This might be buddy as not string is returned by GetType()
  }

  // Create histograms
  //
  // analysisManager->CreateH1("Edep","Energy deposit",100,0.*MeV,10*GeV); //h1 -> this one
  // instantiated with UI
  analysisManager->CreateP1("EdepProfile", "Energy deposit", 1000, 0. * MeV, 50. * GeV, 0.,
                            50. * GeV);  // p1
  analysisManager->CreateH1("Tlen", "Tracks length", 100, 0. * km, 5. * km, "km", "exp");  // h1
  analysisManager->CreateH2("EdepTlen", "Edep Tlen", 100, 0. * MeV, 50 * GeV, 100, 0. * mm,
                            5 * km);  // h2
  analysisManager->CreateH3("EdepTlenEvtID", "Edep Tlen EvtID", 100, 0. * MeV, 50. * GeV, 100,
                            0. * mm, 5. * km, 500, 0., 500.);  // h3

  // Creating ntuple
  //
  analysisManager->CreateNtuple("Ntuple", "Ntuple");
  analysisManager->CreateNtupleDColumn("Energy");
  analysisManager->CreateNtupleDColumn("Length");
  analysisManager->FinishNtuple();

  analysisManager->CreateNtuple("Ntuple2", "Ntuple2");
  analysisManager->CreateNtupleDColumn("Energy2");
  analysisManager->CreateNtupleDColumn("Length2");
  analysisManager->FinishNtuple();
}

void RunAction::EndOfRunAction(const G4Run* /*run*/)
{
  auto analysisManager = G4AnalysisManager::Instance();

  // Some useful methods from the analysisManager
  //
  // Plot histo on file
  //
  analysisManager->SetH1Plotting(0, true);
  // Retrieve information from histos
  //
  G4cout << G4endl << " ----> print histograms statistic ";
  if (isMaster) {
    G4cout << "for the entire run " << G4endl << G4endl;
  }
  else {
    G4cout << "for the local thread " << G4endl << G4endl;
  }
  G4cout << " Edep : mean = " << G4BestUnit(analysisManager->GetH1(0)->mean(), "Energy")
         << " rms = " << G4BestUnit(analysisManager->GetH1(0)->rms(), "Energy") << G4endl;

  // Write and close file
  //
  analysisManager->Write();
  analysisManager->CloseFile();
}

//**************************************************
