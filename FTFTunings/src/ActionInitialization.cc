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
#include "PrimaryGeneratorAction.hh"

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
}

//**************************************************
