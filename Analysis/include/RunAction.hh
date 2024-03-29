//**************************************************
// \file RunAction.hh
// \brief: Declaration of RunAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 24 October 2022
//**************************************************

#ifndef RunAction_h
#  define RunAction_h 1

// Includers from Geant4
//
#  include "G4Run.hh"
#  include "G4UserRunAction.hh"

class RunAction : public G4UserRunAction
{
  public:
    RunAction();
    virtual ~RunAction();

    virtual void BeginOfRunAction(const G4Run*) override;
    virtual void EndOfRunAction(const G4Run*) override;
};

#endif  // RunAction_h 1

//**************************************************
