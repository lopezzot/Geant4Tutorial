//**************************************************
// \file StepAction.cc
// \brief: Definition of StepAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 25 October 2022
//**************************************************

// Includers from project
//
#include "StepAction.hh"
#include "TrackInformation.hh"

// Includers from Geant4
//
#include "G4MuonMinus.hh"
#include "G4Step.hh"

StepAction::StepAction() : G4UserSteppingAction() {}

StepAction::~StepAction() {}

void StepAction::UserSteppingAction(const G4Step *step) {

  // If it is a muon
  //
  if (step->GetTrack()->GetParticleDefinition()->GetPDGEncoding() == 13) {
    TrackInformation *trackInfo =
        static_cast<TrackInformation *>(step->GetTrack()->GetUserInformation());
    if (trackInfo->GetParentPDGID() != -211 &&
        trackInfo->GetParentPDGID() != -321 &&
        trackInfo->GetParentPDGID() != 130) {
      G4cout << trackInfo->GetParentPDGID() << G4endl;
      std::abort();
    }
  }
}

//**************************************************
