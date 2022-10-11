//**************************************************
// \file PLActionInitialization.cc
// \brief: Definition of PLActionInitialization 
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 10 October 2022
//**************************************************

//Includers from project files
//
#include "PLActionInitialization.hh"
#include "PLPrimaryGeneratorAction.hh"

//Constructor
PLActionInitialization::PLActionInitialization() {}

//Destructor
//
PLActionInitialization::~PLActionInitialization() {}

//BuildForMaster method
//
void PLActionInitialization::BuildForMaster() const {}

//Build method
//
void PLActionInitialization::Build() const {
    
    SetUserAction(new PLPrimaryGeneratorAction);

}

//**************************************************
