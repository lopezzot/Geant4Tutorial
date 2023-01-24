//**************************************************
// \file TrackInformation.cc
// \brief: Definition of TrackingInformation class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 20 January 2022
//**************************************************

#include "TrackInformation.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"

G4ThreadLocal G4Allocator<TrackInformation> *aTrackInformationAllocator = 0;

TrackInformation::TrackInformation() : G4VUserTrackInformation() {
  fParentPDGID = 0;
}

TrackInformation::TrackInformation(const G4Track *aTrack)
    : G4VUserTrackInformation() {
  fParentPDGID = 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
TrackInformation ::TrackInformation(const TrackInformation *aTrackInfo)
    : G4VUserTrackInformation() {
  fParentPDGID = 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
TrackInformation::~TrackInformation() { ; }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
TrackInformation &
TrackInformation ::operator=(const TrackInformation &aTrackInfo) {
  fParentPDGID = aTrackInfo.fParentPDGID;
  return *this;
}

void TrackInformation::Print() const {
  G4cout << "Parent track PDG ID " << fParentPDGID << G4endl;
}

//**************************************************
