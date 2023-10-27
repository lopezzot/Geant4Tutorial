//**************************************************
// \file BiasPhysics.hh
// \brief: definition of BiasPhysics class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 27 October 2023
//**************************************************

#ifndef BiasPhysics_h
#  define BiasPhysics_h 1

#  include "G4VPhysicsConstructor.hh"

class BiasPhysics : public G4VPhysicsConstructor
{
  public:
    BiasPhysics();
    ~BiasPhysics() override;

  public:
    void ConstructParticle() override;
    void ConstructProcess() override;
};

#endif

//**************************************************
