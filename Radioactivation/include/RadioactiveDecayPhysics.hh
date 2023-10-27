//physics constructor taken from geant4-11.1/examples/extended/Hadr05/
//to use G4Radioactivation process for radioactive decay
//
#ifndef RadioactiveDecayPhysics_h
#define RadioactiveDecayPhysics_h 1

#include "G4VPhysicsConstructor.hh"
#include "globals.hh"

class RadioactiveDecayPhysics : public G4VPhysicsConstructor
{
  public: 
    RadioactiveDecayPhysics(const G4String& name = "radioactiveDecay");
   ~RadioactiveDecayPhysics() override;

  public:
    void ConstructParticle() override;
    void ConstructProcess() override;

};

#endif
