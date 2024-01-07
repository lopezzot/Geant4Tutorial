//**************************************************
// \file SteppingAction.cc
// \brief: Implementation of SteppingAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 14 December 2023
//**************************************************

#include "SteppingAction.hh"
#include "EventAction.hh"

#include "G4Step.hh"

// Definition of constructor
//
SteppingAction::SteppingAction(EventAction* eventAction)
  : G4UserSteppingAction(),
    fEventAction(eventAction)
{
}

// Definition of deconstructor
//
SteppingAction::~SteppingAction() {}

// Definition of UserSteppingAction() method
//
void SteppingAction::UserSteppingAction(const G4Step* step)
{
}

//**************************************************
