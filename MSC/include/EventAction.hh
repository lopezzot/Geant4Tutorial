//**************************************************
// \file EventAction.hh
// \brief: Definition of EventAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 14 December 2023
//**************************************************

#ifndef EventAction_h
#  define EventAction_h 1

// Includers from Gean4
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

    void SavePxPy(G4double px, G4double py);

  private:
    G4double fpy;
    G4double fpx;
};

inline void EventAction::SavePxPy(G4double px, G4double py)
{
  fpy = py;
  fpx = px;
}

#endif

//**************************************************
