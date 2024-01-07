//**************************************************
// \file SteppingAction.hh
// \brief: Definition of SteppingAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 14 December 2023
//**************************************************

#ifndef SteppingAction_h
#  define SteppingAction_h 1

#  include "G4UserSteppingAction.hh"

class EventAction;

class SteppingAction : public G4UserSteppingAction
{
  public:
    SteppingAction(EventAction* eventAction);
    virtual ~SteppingAction();

    virtual void UserSteppingAction(const G4Step* step);

  private:
    EventAction* fEventAction;
};

#endif

//**************************************************
