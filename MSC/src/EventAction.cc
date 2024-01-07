//**************************************************
// \file EventAction.cc
// \brief: Implementation of EventAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 14 December 2023
//**************************************************

#include "EventAction.hh"

//#include "RunAction.hh"

// Includers from Geant4
//
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4Version.hh"
#if G4VERSION_NUMBER < 1100
#  include "g4root.hh"
#else
#  include "G4AnalysisManager.hh"
#endif

// Define constructor
//
EventAction::EventAction()
  : G4UserEventAction(),
    fpy(0.),
    fpx(0.)
{}

// Define deconstructor
//
EventAction::~EventAction() {}

// Define BeginOfEventAction() and EndOfEventAction() methods
//
void EventAction::BeginOfEventAction(const G4Event*)
{
  // Initialize variables per event
  //
  fpx = 0.;
  fpy = 0.;
}

void EventAction::EndOfEventAction(const G4Event*)
{
  // Access Event random seeds
  //
  // auto rndseed = G4RunManager::GetRunManager()->GetRandomNumberStatusForThisEvent();

  // Accumulate statistics
  //
  auto analysisManager = G4AnalysisManager::Instance();
  analysisManager->FillNtupleDColumn(0, fpx);
  analysisManager->FillNtupleDColumn(1, fpy);
  analysisManager->AddNtupleRow();

}

//**************************************************
