//**************************************************
// \file ActionInitialization.cc
// \brief: Definition of ActionInitialization
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 24 October 2023
//**************************************************

// Includers from project files
//
#include "ActionInitialization.hh"

#include "PrimaryGeneratorAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "RunAction.hh"

// Constructor
ActionInitialization::ActionInitialization() {}

// Destructor
//
ActionInitialization::~ActionInitialization() {}

// BuildForMaster method
//
void ActionInitialization::BuildForMaster() const {}

// Build method
//
void ActionInitialization::Build() const
{
  SetUserAction(new PrimaryGeneratorAction);
  auto eventAction = new EventAction;
  SetUserAction(new RunAction);
  SetUserAction(eventAction);
  SetUserAction(new SteppingAction(eventAction));
}

//**************************************************
