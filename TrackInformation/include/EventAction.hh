//**************************************************
// \file EventAction.hh
// \brief: Declaration of EventAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 23 January 2022
//**************************************************

#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class EventAction : public G4UserEventAction {

public:
  EventAction();
  virtual ~EventAction();

  void BeginOfEventAction(const G4Event *anEvent) override;
  void EndOfEventAction(const G4Event *anEvent) override;

  inline void AddKMinusMu() { fKMinusMu++; }
  inline void AddKLMu() { fKLMu++; }
  inline void AddPiMu() { fPiMu++; }

private:
  G4int fKMinusMu;
  G4int fKLMu;
  G4int fPiMu;
};

#endif // EventAction_h 1

//**************************************************