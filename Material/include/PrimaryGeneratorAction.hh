//**************************************************
// \file PrimaryGeneratorAction.hh
// \brief: Declaration of PrimaryGeneratorAction
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 17 October 2022
//**************************************************

#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

// Includers from Geant4
//
#include "G4ParticleGun.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"

// Forward declaration from Geant4
//
class G4ParticleGun;
class G4Event;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {

public:
  PrimaryGeneratorAction();
  ~PrimaryGeneratorAction() override;

  // Method from the base class
  // this method is called at the beginning of each event
  //
  void GeneratePrimaries(G4Event *) override;

private:
  G4ParticleGun *fParticleGun = nullptr; // pointer a to G4 gun class
};

#endif // PrimaryGeneratorAction_h 1

//**************************************************
