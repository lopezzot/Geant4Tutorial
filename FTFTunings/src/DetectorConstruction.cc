//**************************************************
// \file DetectorConstruction.cc
// \brief: Definition of DetectorConstruction
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 24 October 2022
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

// Definition of constructor
//
DetectorConstruction::DetectorConstruction() {}

// Definition of deconstructor
//
DetectorConstruction::~DetectorConstruction() {}

// Definition of Construct() method
//
G4VPhysicalVolume *DetectorConstruction::Construct() {

  // Create a simple box of absorber in air
  // geometry is not relevant for PhysicsList tutorial
  //

  // Get nist manager and G4_WATER material
  //
  G4NistManager *nist = G4NistManager::Instance();
  G4Material *fe = nist->FindOrBuildMaterial("G4_Fe");
  G4Material *air = nist->FindOrBuildMaterial("G4_AIR");

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
  G4Box *solidBox = new G4Box("Box", 1. * m, 1. * m, 1. * m);
  G4LogicalVolume *logicBox = new G4LogicalVolume(solidBox, fe, "Box");
  new G4PVPlacement(0,               // no rotation
                    G4ThreeVector(), // at (0,0,0)
                    logicBox,        // its logical volume
                    "World",         // its name
                    logicWorld,      // its mother volume
                    false,           // no boolean operation
                    0,               // its copy number
                    false);          // overlaps checking

  return physWorld;
}

//**************************************************
