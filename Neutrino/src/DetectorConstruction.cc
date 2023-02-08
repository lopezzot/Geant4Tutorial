//**************************************************
// \file DetectorConstruction.cc
// \brief: Definition of DetectorConstruction
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 17 October 2022
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
#include "G4Region.hh"
#include "G4SystemOfUnits.hh"

// Definition of constructor
//
DetectorConstruction::DetectorConstruction() {}

// Definition of deconstructor
//
DetectorConstruction::~DetectorConstruction() {}

// Definition of Construct() method
//
G4VPhysicalVolume *DetectorConstruction::Construct() {

  G4NistManager *nist = G4NistManager::Instance();
  G4Material *air = nist->FindOrBuildMaterial("G4_AIR");
  G4Material *fe = nist->FindOrBuildMaterial("G4_Fe");

  // World (box)
  //
  G4Box *solidWorld = new G4Box("World", 1.5 * m, 1.5 * m, 1.5 * m);
  G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, air, "World");
  G4VPhysicalVolume *physWorld =
      new G4PVPlacement(0,               // no rotation
                        G4ThreeVector(), // at (0,0,0)
                        logicWorld,      // its logical volume
                        "World",         // its name
                        0,               // its mother volume
                        false,           // no boolean operation
                        0,               // its copy number
                        false);          // overlaps checking

  // Box of absorber
  //
  G4Box *solidBox = new G4Box("Box", 0.5 * m, 0.5 * m, 0.5 * m);
  G4LogicalVolume *logicBox = new G4LogicalVolume(solidBox, fe, "Box");
  new G4PVPlacement(0,               // no rotation
                    G4ThreeVector(), // at (0,0,0)
                    logicBox,        // its logical volume
                    "Absorber",      // its name
                    logicWorld,      // its mother volume
                    false,           // no boolean operation
                    0,               // its copy number
                    false);          // overlaps checking

  // Assign region
  //
  G4Region *neutrinoRegion = new G4Region("neutrinoRegion");
  logicBox->SetRegion(neutrinoRegion);
  neutrinoRegion->AddRootLogicalVolume(logicBox);

  return physWorld;
}

//**************************************************
