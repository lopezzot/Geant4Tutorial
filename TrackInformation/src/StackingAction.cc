//**************************************************
// \file StackingAction.cc
// \brief: Definition of StackingAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 23 January 2022
//**************************************************

#include "StackingAction.hh"
#include "G4Track.hh"
#include "TrackInformation.hh"

StackingAction::StackingAction() : G4UserStackingAction() { ; }

StackingAction::~StackingAction() { ; }

G4ClassificationOfNewTrack
StackingAction::ClassifyNewTrack(const G4Track *aTrack) {

  // Attach custom TrackInformation to primary particle track
  //
  TrackInformation *trackInfo;
  if (aTrack->GetParentID() == 0) {
    // Create TrackInformation and assign fParentPDGID as 0
    //
    trackInfo = new TrackInformation(aTrack);
    trackInfo->SetParentPDGID(0);
    // Attach customTrackInformation to current track
    //
    G4Track *theTrack = (G4Track *)aTrack;
    theTrack->SetUserInformation(trackInfo);
  }

  G4ClassificationOfNewTrack classification = fUrgent;

  return classification;
}

void StackingAction::NewStage() { ; }
void StackingAction::PrepareNewEvent() { ; }

//**************************************************