//**************************************************
// \file TrackInformation.hh
// \brief: Declaration of TrackingInformation class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 20 January 2023
//**************************************************

#ifndef TrackInformation_h
#define TrackInformation_h 1

#include "G4Allocator.hh"
#include "G4ParticleDefinition.hh"
#include "G4ThreeVector.hh"
#include "G4Track.hh"
#include "G4VUserTrackInformation.hh"
#include "globals.hh"

class TrackInformation : public G4VUserTrackInformation {

public:
  TrackInformation();
  TrackInformation(const G4Track *aTrack);
  TrackInformation(const TrackInformation *aTrackInfo);
  virtual ~TrackInformation();

  inline void *operator new(size_t);
  inline void operator delete(void *aTrackInfo);

  TrackInformation &operator=(const TrackInformation &right);

  virtual void Print() const;

public:
  inline G4int GetParentPDGID() const { return fParentPDGID; }
  inline void SetParentPDGID(G4int i) { fParentPDGID = i; }

private:
  G4int fParentPDGID; // PDGID of the parent particle
};

extern G4ThreadLocal G4Allocator<TrackInformation> *aTrackInformationAllocator;

inline void *TrackInformation::operator new(size_t) {
  if (!aTrackInformationAllocator)
    aTrackInformationAllocator = new G4Allocator<TrackInformation>;
  return (void *)aTrackInformationAllocator->MallocSingle();
}

inline void TrackInformation::operator delete(void *aTrackInfo) {
  aTrackInformationAllocator->FreeSingle((TrackInformation *)aTrackInfo);
}

#endif // TrackInformation_h 1

//**************************************************