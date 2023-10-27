//physics constructor taken from geant4-11.1/examples/extended/Hadr05/
//to use G4Radioactivation process for radioactive decay
//
#include "RadioactiveDecayPhysics.hh"

#include "G4Radioactivation.hh"
#include "G4GenericIon.hh"
#include "G4PhysicsListHelper.hh"
#include "G4EmParameters.hh"
#include "G4VAtomDeexcitation.hh"
#include "G4UAtomicDeexcitation.hh"
#include "G4LossTableManager.hh"
#include "G4NuclearLevelData.hh"
#include "G4DeexPrecoParameters.hh"
#include "G4NuclideTable.hh"
#include "G4SystemOfUnits.hh"

RadioactiveDecayPhysics::RadioactiveDecayPhysics(const G4String& name)
:  G4VPhysicsConstructor(name)
{
  // hadronic physics extra configuration
  //
  G4DeexPrecoParameters* deex = 
     G4NuclearLevelData::GetInstance()->GetParameters();     
  deex->SetStoreICLevelData(true);
  deex->SetMaxLifeTime(G4NuclideTable::GetInstance()->GetThresholdOfHalfLife()
                       /std::log(2.));
  deex->SetIsomerProduction(true);
  deex->SetCorrelatedGamma(false);
}

RadioactiveDecayPhysics::~RadioactiveDecayPhysics()
{ }

void RadioactiveDecayPhysics::ConstructParticle()
{
  G4GenericIon::GenericIon();
}

void RadioactiveDecayPhysics::ConstructProcess()
{
  G4Radioactivation* radioactiveDecay = new G4Radioactivation();

  G4bool ARMflag = false;
  radioactiveDecay->SetARM(ARMflag);        //Atomic Rearangement

  // EM physics extra configuration
  // this physics constructor should be defined after EM constructor
  G4EmParameters::Instance()->SetFluo(ARMflag);  
  G4EmParameters::Instance()->SetAugerCascade(ARMflag);
  G4EmParameters::Instance()->SetDeexcitationIgnoreCut(ARMflag);

  G4LossTableManager* man = G4LossTableManager::Instance();
  G4VAtomDeexcitation* ad = man->AtomDeexcitation();

  // EM physics constructors are not used
  if( ad == nullptr ) {
    ad = new G4UAtomicDeexcitation();
    man->SetAtomDeexcitation(ad);
    man->ResetParameters();
  }

  G4PhysicsListHelper::GetPhysicsListHelper()->
    RegisterProcess(radioactiveDecay, G4GenericIon::GenericIon());
}
