//**************************************************
// \file EventAction.cc
// \brief: Implementation of EventAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 25 October 2022
//**************************************************

//Includers from project files
//
#include "EventAction.hh"

//Includers from Geant4
//
#include "G4Version.hh"
#if G4VERSION_NUMBER < 1100
#include "g4root.hh"  // replaced by G4AnalysisManager.h  in G4 v11 and up
#else
#include "G4AnalysisManager.hh"
#endif

EventAction::EventAction() :
    TrackL(0.),
    Edep(0.){}

EventAction::~EventAction(){}

void EventAction::BeginOfEventAction(const G4Event*){
    
    TrackL = 0.;
    Edep = 0.;

}

void EventAction::EndOfEventAction(const G4Event*){
    
    auto AnalysisManager = G4AnalysisManager::Instance();
    AnalysisManager->FillH1(0, Edep); //MeV
    AnalysisManager->FillH1(1, TrackL);//mm
    G4cout<<TrackL<<" "<<Edep<<G4endl;
}

//**************************************************
