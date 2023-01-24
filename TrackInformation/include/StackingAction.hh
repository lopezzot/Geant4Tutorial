//**************************************************
// \file StackingAction.hh
// \brief: Declaration of StackingAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 23 January 2022
//**************************************************

#ifndef StackingAction_h
#define StackingAction_h 1

#include "G4UserStackingAction.hh"
#include "globals.hh"

class G4Track;
class G4VHitsCollection;

class StackingAction : public G4UserStackingAction {

public:
  StackingAction();
  virtual ~StackingAction();

  virtual G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track *aTrack);
  virtual void NewStage();
  virtual void PrepareNewEvent();
};

#endif // StackingAction_h 1

//**************************************************