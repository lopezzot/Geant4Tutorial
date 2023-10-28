//**************************************************
// \file StepAction.cc
// \brief: Definition of StepAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 25 October 2022
//**************************************************

// Includers from project
//
#include "StepAction.hh"

#include "EventAction.hh"

// Inclyders from Geant4
//
#include "G4Step.hh"

StepAction::StepAction(EventAction* evtactn) : G4UserSteppingAction(), fEventAction(evtactn) {}

StepAction::~StepAction() {}

void StepAction::UserSteppingAction(const G4Step* step)
{
  fEventAction->AddEdep(step->GetTotalEnergyDeposit());
  fEventAction->AddTrackL(step->GetStepLength());
}

//**************************************************
