//**************************************************
// \file ActionInitialization.cc
// \brief: Definition of ActionInitialization
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 24 October 2022
//**************************************************

// Includers from project files
//
#include "ActionInitialization.hh"

#include "EventAction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "StepAction.hh"

// Constructor
//
ActionInitialization::ActionInitialization() {}

// Destructor
//
ActionInitialization::~ActionInitialization() {}

// BuildForMaster method
//
void ActionInitialization::BuildForMaster() const
{
  SetUserAction(new RunAction);
}

// Build method
//
void ActionInitialization::Build() const
{
  auto eventaction = new EventAction();

  SetUserAction(new PrimaryGeneratorAction);
  SetUserAction(new RunAction);
  SetUserAction(eventaction);
  SetUserAction(new StepAction(eventaction));
}

//**************************************************
