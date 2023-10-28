//**************************************************
// \file StepAction.hh
// \brief: Declaration of StepAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 25 October 2022
//**************************************************

#ifndef StepAction_h
#  define StepAction_h 1

// Includers from Geant4
//
#  include "G4UserSteppingAction.hh"
class EventAction;

class StepAction : public G4UserSteppingAction
{
  public:
    StepAction(EventAction* evtactn);
    virtual ~StepAction();

    virtual void UserSteppingAction(const G4Step* step);

  private:
    EventAction* fEventAction;
};

#endif  // StepAction_h 1

//**************************************************
