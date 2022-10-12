//**************************************************
// \file PLModular.cc
// \brief: Definition of PLModular class 
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 11 October 2022
//**************************************************

//Includers from project files
//
#include "PLModular.hh"
#include "SystemOfUnits.hh"

//Constructor (physics is registered here)
//
PLModular::PLModular()
         : G4VModularPhysicsList() {
    
    //set default cut value
    //optional
    //
    defaultCutValue = 0.7*mm;

         
         
}





















//**************************************************

