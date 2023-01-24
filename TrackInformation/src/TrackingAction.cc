//**************************************************
// \file TrackingAction.cc
// \brief: Definition of TrackingAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 19 January 2022
//**************************************************

#include "TrackingAction.hh"
#include "G4ParticleDefinition.hh"
#include "G4Track.hh"
#include "G4TrackVector.hh"
#include "G4TrackingManager.hh"
#include "TrackInformation.hh"
#include "globals.hh"

TrackingAction::TrackingAction(EventAction *theEvtAction)
    : G4UserTrackingAction(), fEventAction(theEvtAction) {
  ;
}

void TrackingAction::PreUserTrackingAction(const G4Track *aTrack) {

  if (aTrack->GetParentID() == 0) {
    // Create TrackInformation and assign fParentPDGID as 0
    //
    auto PrimaryTrackInfo =
        new TrackInformation(); // fParentPDGID = 0 by constructor
    // Attach customTrackInformation to current track
    //
    G4Track *theTrack = (G4Track *)aTrack;
    theTrack->SetUserInformation(PrimaryTrackInfo);
  }

  TrackInformation *trackInfo =
      static_cast<TrackInformation *>(aTrack->GetUserInformation());
  /*G4cout << aTrack->GetParticleDefinition()->GetParticleName() << G4endl;
  G4cout << "Parent track ID " << aTrack->GetParentID() << G4endl;
  trackInfo->Print();*/
  // If current track is a mu-
  //
  if (aTrack->GetParticleDefinition()->GetPDGEncoding() == 13) {
    if (trackInfo->GetParentPDGID() == -211) {
      fEventAction->AddPiMu();
    } else if (trackInfo->GetParentPDGID() == -321) {
      fEventAction->AddKMinusMu();
    } else if (trackInfo->GetParentPDGID() == 130) {
      fEventAction->AddKLMu();
    } else {
      ;
    }
  }
}

void TrackingAction::PostUserTrackingAction(const G4Track *aTrack) {

  // Get secondaries of track
  //
  G4TrackVector *secondaries = fpTrackingManager->GimmeSecondaries();

  if (secondaries) {                         // if secondaries exist
    std::size_t nSeco = secondaries->size(); // number of secondaries
    if (nSeco > 0) {
      for (size_t i = 0; i < nSeco; i++) {
        TrackInformation *infoNew = new TrackInformation();
        infoNew->SetParentPDGID(
            aTrack->GetParticleDefinition()->GetPDGEncoding());
        (*secondaries)[i]->SetUserInformation(infoNew);
      }
    }
  }
}

//**************************************************
