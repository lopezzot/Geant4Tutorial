//**************************************************
// \file EventAction.hh
// \brief: Declaration of EventAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 25 October 2022
//**************************************************

#ifndef EventAction_h
#  define EventAction_h

// Includers from Geant4
//
#  include "G4UserEventAction.hh"
#  include "globals.hh"

class EventAction : public G4UserEventAction
{
  public:
    EventAction();
    virtual ~EventAction();

    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);

    void AddTrackL(G4double dl);
    void AddEdep(G4double de);

  private:
    G4double TrackL;
    G4double Edep;
};

inline void EventAction::AddTrackL(G4double dl)
{
  TrackL += dl;
}

inline void EventAction::AddEdep(G4double de)
{
  Edep += de;
}

#endif  // EventAction_h

//**************************************************
