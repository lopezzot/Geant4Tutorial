//**************************************************
// \file PLPrimaryGeneratorAction.hh
// \brief: Declaration of PLPrimaryGeneratorAction 
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 10 October 2022
//**************************************************

#ifndef PLPrimaryGeneratorAction_h
#define PLPrimaryGeneratorAction_h 1

//Includers from Geant4
//
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

//Forward declaration from Geant4
//
class G4ParticleGun;
class G4Event;

class PLPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
    
    public:
        PLPrimaryGeneratorAction();
        ~PLPrimaryGeneratorAction() override;

        //Method from the base class
        //this method is called at the beginning of each event
        //
        void GeneratePrimaries(G4Event*) override;

    private:
        G4ParticleGun* fParticleGun = nullptr; // pointer a to G4 gun class
};

#endif //PLPrimaryGeneratorAction_h 1

//**************************************************
