//**************************************************
// \file NeutrinoConstructor.hh
// \brief: Declaration of NeutrinoConstructor class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 13 December 2022
//**************************************************

#ifndef NeutrinoConstructor_h
#define NeutrinoConstructor_h

#include "G4VPhysicsConstructor.hh"

class NeutrinoConstructor : public G4VPhysicsConstructor {

public:
  NeutrinoConstructor(G4int ver = 1);
  virtual ~NeutrinoConstructor();

  virtual void ConstructParticle() override;
  virtual void ConstructProcess() override;
};

#endif // NeutrinoConstructor_h

//**************************************************
