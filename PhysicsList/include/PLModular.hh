//**************************************************
// \file PLModular.hh
// \brief: Declaration of PLModular class 
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 11 October 2022
//**************************************************

#ifndef PLModular_h
#define PLModular_h 1

//Includers from Geant4
//
#include "G4VModularPhysicsList.hh"

class PLModular : public G4VModularPhysicsList {

    public:
        PLModular();
        ~PLModular();

        //Copy constructor and
        //assignment operator = delete
        //
        PLModular(const PLModular&) = delete;
        PLModular& operator=(const PLModular&) = delete;

};

#endif //PLModular_h 1

//**************************************************

