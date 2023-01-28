//**************************************************
// \file ActionInitialization.hh
// \brief: Declaration of ActionInitialization
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 17 October 2022
//**************************************************

#ifndef ActionInitialization_h
#define ActionInitialization_h 1

// Includers from Geant4
//
#include "G4VUserActionInitialization.hh"

class ActionInitialization : public G4VUserActionInitialization {

public:
  ActionInitialization();
  ~ActionInitialization() override;

  void BuildForMaster() const override;
  void Build() const override;
};

#endif // ActionInitialization_h 1

//**************************************************
