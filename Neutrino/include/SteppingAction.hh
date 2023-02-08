//**************************************************
// \file SteppingAction.hh
// \brief: Declaration of SteppingAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 13 December 2022
//**************************************************

#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "G4UserSteppingAction.hh"

class SteppingAction : public G4UserSteppingAction {

public:
  SteppingAction();
  virtual ~SteppingAction();

  virtual void UserSteppingAction(const G4Step *aStep);
};

#endif // SteppingAction_h 1

//**************************************************
