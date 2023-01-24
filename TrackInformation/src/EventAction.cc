//**************************************************
// \file EventAction.cc
// \brief: Definition of EventAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 23 January 2022
//**************************************************

#include "EventAction.hh"
#include "G4AnalysisManager.hh"

EventAction::EventAction()
    : G4UserEventAction(), fKMinusMu(0), fKLMu(0), fPiMu(0) {
  ;
}

EventAction::~EventAction() { ; }

void EventAction::BeginOfEventAction(const G4Event *anEvent) {

  fKMinusMu = 0;
  fKLMu = 0;
  fPiMu = 0;
}

void EventAction::EndOfEventAction(const G4Event *anEvent) {

  auto AnalysisManager = G4AnalysisManager::Instance();
  AnalysisManager->FillNtupleIColumn(0, fKMinusMu);
  AnalysisManager->FillNtupleIColumn(1, fKLMu);
  AnalysisManager->FillNtupleIColumn(2, fPiMu);
  AnalysisManager->AddNtupleRow();
}

//**************************************************