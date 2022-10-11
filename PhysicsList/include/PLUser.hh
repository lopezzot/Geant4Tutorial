//**************************************************
// \file PLUser.hh
// \brief: Declaration of PLUser class 
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 10 October 2022
//**************************************************

#ifndef PLUser_h
#define PLUser_h 1

//Includers from Geant4
//
#include "G4VUserPhysicsList.hh"

class PLUser : public G4VUserPhysicsList {

    public:
        PLUser();
        ~PLUser() override;

        //Pure virtual methods to be implemented
        //in each user PL. 
        //
        virtual void ConstructParticle() override;
        //this process is called by RunManager
        //and instantiate particles.
        virtual void ConstructProcess() override;
        //this process is invoked by Construct()
        //of G4VUserPhysicsList class
        //each physics process will be instantiated
        //and registered to the process manager
        //of each particle.
        
        //Virtual method to set a cut value
        //for all particle types in the particle 
        //table (optional)
        //virtual void SetCuts() override;

};

#endif //PLUser_h 1

//**************************************************

