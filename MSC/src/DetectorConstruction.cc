//**************************************************
// \file DetectorConstruction.cc
// \brief: Definition of DetectorConstruction
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 24 October 2023
//**************************************************

// Includers from project files
//
#include "DetectorConstruction.hh"

// Includers from Geant4
//
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"

// Definition of constructor
//
DetectorConstruction::DetectorConstruction() {}

// Definition of deconstructor
//
DetectorConstruction::~DetectorConstruction() {}

// Definition of Construct() method
//
G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Get nist manager (singleton)
  //
  G4NistManager* nist = G4NistManager::Instance();

  // Get Air material from NIST
  //
  G4Material* air = nist->FindOrBuildMaterial("G4_AIR");
  G4cout << "Built from NIST: " << air->GetName() << G4endl;

  // Get DUT material from NIST
  //
  G4Material* DUTmaterial = nist->FindOrBuildMaterial("G4_Fe");
  G4cout << "Built from NIST: " << DUTmaterial->GetName() << G4endl;

  // World (box)
  //
  G4Box* solidWorld = new G4Box("World", 15. * m, 15. * m, 15. * m);
  G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, air, "World");
  auto WorldVisAttributes = new G4VisAttributes();
  WorldVisAttributes->SetForceWireframe(true);
  logicWorld->SetVisAttributes(WorldVisAttributes);
  G4VPhysicalVolume* physWorld = new G4PVPlacement(0,  // no rotation
                                                   G4ThreeVector(),  // at (0,0,0)
                                                   logicWorld,  // its logical volume
                                                   "World",  // its name
                                                   0,  // its mother volume
                                                   false,  // no boolean operation
                                                   0,  // its copy number
                                                   false);  // overlaps checking

  // Box of absorber
  //
  G4double DUTthickness = 5.*mm;
  G4double DUTsize = 1.*m;
  G4Box* solidBox = new G4Box("AbsorberBox", DUTsize, DUTsize, DUTthickness);
  G4LogicalVolume* logicBox = new G4LogicalVolume(solidBox, DUTmaterial, "AbsorberBox");
  auto BoxVisAttributes = new G4VisAttributes();
  BoxVisAttributes->SetForceWireframe(true);
  logicBox->SetVisAttributes(BoxVisAttributes);
  new G4PVPlacement(0,  // no rotation
                    G4ThreeVector(),  // at (0,0,0)
                    logicBox,  // its logical volume
                    "AbsorberBox",  // its name
                    logicWorld,  // its mother volume
                    false,  // no boolean operation
                    0,  // its copy number
                    false);  // overlaps checking

  return physWorld;
}

//**************************************************
