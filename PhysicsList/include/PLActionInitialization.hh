//**************************************************
// \file PLActionInitialization.hh
// \brief: Declaration of PLActionInitialization 
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 10 October 2022
//**************************************************

#ifndef PLActionInitialization_h
#define PLActionInitialization_h 1

//Includers from Geant4
//
#include "G4VUserActionInitialization.hh"

class PLActionInitialization : public G4VUserActionInitialization {
    
    public:
        PLActionInitialization();
        ~PLActionInitialization() override;

        void BuildForMaster() const override;
        void Build() const override;

};

#endif //PLActionInitialization_h 1

//**************************************************
