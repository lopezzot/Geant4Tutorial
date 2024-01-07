//**************************************************
// \file RunAction.hh
// \brief: Definition of RunAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 14 December 2023
//**************************************************

#ifndef RunAction_h
#  define RunAction_h 1

// Includers from Geant4
//
#  include "G4UserRunAction.hh"
#  include "globals.hh"

class G4Run;

class RunAction : public G4UserRunAction
{
  public:
    RunAction();
    virtual ~RunAction();

    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);

  private:
};

#endif

//**************************************************
