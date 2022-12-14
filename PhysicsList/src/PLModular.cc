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
#include "G4SystemOfUnits.hh"
#include "G4EmStandardPhysics.hh"
#include "G4HadronPhysicsFTFP_BERT.hh"
#include "G4DecayPhysics.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4Electron.hh"
#include "G4Gamma.hh"

//Constructor (physics is registered here)
//
PLModular::PLModular()
    : G4VModularPhysicsList() {
    
    //Set default cut value
    //(optional)
    //
    defaultCutValue = 0.7*mm;

    //Register pre-defined physics constructors
    //includes constructions of all EM processes
    //and related particles
    //
    //RegisterPhysics(new G4EmStandardPhysics());

    //Decays
    //
    //RegisterPhysics( new G4DecayPhysics() );

    //Hadron Elastic scattering
    //
    //RegisterPhysics( new G4HadronElasticPhysics() );

    //Hadron physics FTFP+BERT
    //
    RegisterPhysics(new G4HadronPhysicsFTFP_BERT());
     
}

//Destructor
//
PLModular::~PLModular() {}


//**************************************************

