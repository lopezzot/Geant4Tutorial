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
#include "StackingAction.hh"
#include "StepAction.hh"
#include "TrackingAction.hh"

// Constructor
//
ActionInitialization::ActionInitialization() {}

// Destructor
//
ActionInitialization::~ActionInitialization() {}

// BuildForMaster method
//
void ActionInitialization::BuildForMaster() const {}

// Build method
//
void ActionInitialization::Build() const {

  SetUserAction(new PrimaryGeneratorAction);
  SetUserAction(new StepAction());
  auto theEvtAction = new EventAction();
  SetUserAction(theEvtAction);
  SetUserAction(new TrackingAction(theEvtAction));
  // SetUserAction(new StackingAction());
  // StackingAction not used
  // track info is handled entirely
  // by TrackingAction
  SetUserAction(new RunAction());
}

//**************************************************
