//**************************************************
// \file BiasPhysicsConstructor.hh
// \brief: Declaration of BiasPhysicsConstructor
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 13 December 2022
//**************************************************

#ifndef BiasPhysicsConstructor_h
#define BiasPhysicsConstructor_h

#include "G4VPhysicsConstructor.hh"

class BiasPhysicsConstructor : public G4VPhysicsConstructor {

public:
  BiasPhysicsConstructor();
  ~BiasPhysicsConstructor() override;

  virtual void ConstructParticle() override;
  virtual void ConstructProcess() override;
};

#endif // BiasPhysicsConstructor_h

//**************************************************
