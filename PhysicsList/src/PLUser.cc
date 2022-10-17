//**************************************************
// \file PLUser.cc
// \brief: Definition of PLUser class 
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 10 October 2022
//**************************************************

//Includers from project files
//
#include "PLUser.hh"

//Includers from Geant4
//
#include "G4Electron.hh"
#include "G4Gamma.hh"
#include "G4Positron.hh"
#include "G4LeptonConstructor.hh"
#include "G4eBremsstrahlung.hh"
#include "G4PhysicsListHelper.hh"
#include "G4GammaConversion.hh"
#include "G4ComptonScattering.hh"
#include "G4PhotoElectricEffect.hh"
#include "G4eIonisation.hh"
#include "G4eMultipleScattering.hh"
#include "G4CoulombScattering.hh"
#include "G4Proton.hh"
#include "G4eDPWACoulombScatteringModel.hh"
#include "G4EmParameters.hh"

//Constructor
//
PLUser::PLUser() {}

//Destructor
//
PLUser::~PLUser() {}

//ConstructParticle method
//
void PLUser::ConstructParticle() {
    
    //Construct each particle independently
    //
    G4Electron::Definition();
    G4Gamma::Definition();
    G4Positron::Definition();
    G4Proton::Definition();

    //Or use constructors for groups of
    //particles. Example:
    //e-,nu_e, mu-, nu_mu, t-, nu_t
    //and antiparticles
    //
    //G4LeptonConstructor leptonConstructor;
    //leptonConstructor.ConstructParticle();

}

//ConstructProcess method
//
void PLUser::ConstructProcess() {
    
    //This method (defined in the G4VUserPhysicsList class)
    //assigns the transportation process to all particles
    //defined in ConstructParticle()
    AddTransportation();

    //Processes must the assigned to particles,
    //to iterate through the particles in Construct()
    //use the particleIterator, to register processes
    //use the PhysicsListHelper
    //
    auto plHelper = G4PhysicsListHelper::GetPhysicsListHelper();
    auto particleIterator = GetParticleIterator();
    particleIterator->reset();
    auto msc = new G4CoulombScattering();
    msc->SetEmModel(new G4eDPWACoulombScatteringModel());
    G4EmParameters::Instance()->SetMscThetaLimit(0.0);
    //iterate over list of particles
    //
    while( (*particleIterator)() ){
        //get current particle definition
        G4ParticleDefinition* particleDef = particleIterator->value();
        if (particleDef == G4Gamma::Definition()){
            //add processes to gamma
            //plHelper->RegisterProcess(new G4GammaConversion(), particleDef);
            //plHelper->RegisterProcess(new G4ComptonScattering(), particleDef);
            //plHelper->RegisterProcess(new G4PhotoElectricEffect(), particleDef);
        } else if (particleDef == G4Electron::Definition()) {
            //add processes to electron
            //plHelper->RegisterProcess(new G4eBremsstrahlung(), particleDef);
            //plHelper->RegisterProcess(new G4eIonisation(), particleDef);
            plHelper->RegisterProcess(msc, particleDef);
        }
    }

}

//**************************************************
