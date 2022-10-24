//**************************************************
// \file PrimaryGeneratorAction.cc
// \brief: Definition of PrimaryGeneratorAction 
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 24 October 2022
//**************************************************

//Includers from project files
//
#include "PrimaryGeneratorAction.hh"

//Includers from Geant4
//
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"

//Constructor
//
PrimaryGeneratorAction::PrimaryGeneratorAction() {

    G4int n_particle = 1;
    fParticleGun  = new G4ParticleGun(n_particle);
    
    //Default beam particle kinematic
    //
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName;
    G4ParticleDefinition* particle
        = particleTable->FindParticle(particleName="e-");
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
    fParticleGun->SetParticleEnergy(100.*MeV);
    fParticleGun->SetParticlePosition(G4ThreeVector(0.,0.,-1.0*m));

}

//Destructor
//
PrimaryGeneratorAction::~PrimaryGeneratorAction() { delete fParticleGun; }

//GeneratePrimaries override
//
void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {

    fParticleGun->GeneratePrimaryVertex(anEvent);

}

//**************************************************
