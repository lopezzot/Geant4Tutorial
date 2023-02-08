//**************************************************
// \file SteppingAction.cc
// \brief: Definition of SteppingAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 13 December 2022
//**************************************************

#include "SteppingAction.hh"
#include "G4Step.hh"

SteppingAction::SteppingAction() {}

SteppingAction::~SteppingAction() {}

void SteppingAction::UserSteppingAction(const G4Step *aStep) {

  G4cout << aStep->GetPreStepPoint()
                ->GetPhysicalVolume()
                ->GetLogicalVolume()
                ->GetRegion()
                ->GetName()
         << G4endl;
}

//**************************************************
