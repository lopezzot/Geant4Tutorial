//**************************************************
// \file TrackingAction.hh
// \brief: Declaration of TrackingAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 19 January 2023
//**************************************************

#ifndef TrackingAction_h
#define TrackingAction_h

#include "EventAction.hh"
#include "G4Track.hh"
#include "G4UserTrackingAction.hh"

class TrackingAction : public G4UserTrackingAction {

public:
  TrackingAction(EventAction *theEvtAction);
  virtual ~TrackingAction(){};

  virtual void PreUserTrackingAction(const G4Track *);
  virtual void PostUserTrackingAction(const G4Track *);

private:
  EventAction *fEventAction;
};

#endif // TrackingAction_h

//**************************************************
