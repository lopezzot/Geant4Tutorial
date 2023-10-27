//**************************************************
// \file PrimaryGeneratorAction.cc
// \brief: Definition of PrimaryGeneratorAction
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 24 October 2023
//**************************************************

// Includers from project files
//
#include "PrimaryGeneratorAction.hh"

// Includers from Geant4
//
#include "G4IonTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"

// Constructor
//
PrimaryGeneratorAction::PrimaryGeneratorAction()
{
  fParticleGun = new G4ParticleGun();
}

// Destructor
//
PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleGun;
}

// GeneratePrimaries override
//
void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  // Simulate 60Co radioactive decay
  //
  G4int Z = 27;
  G4int A = 60;
  G4double charge = 0. * eplus;
  G4double energy = 0. * keV;
  G4ParticleDefinition* ion = G4IonTable::GetIonTable()->GetIon(Z, A, energy);

  fParticleGun->SetParticleDefinition(ion);
  fParticleGun->SetParticleCharge(charge);
  fParticleGun->SetParticleEnergy(0. * MeV);  // at rest

  fParticleGun->GeneratePrimaryVertex(anEvent);
}

//**************************************************
