//**************************************************
// \file DetectorConstruction.cc
// \brief: Definition of DetectorConstruction 
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 17 October 2022
//**************************************************

//Includers from project files
//
#include "DetectorConstruction.hh"

//Includers from Geant4
//
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4SystemOfUnits.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4Material.hh"

//Definition of constructor
//
DetectorConstruction::DetectorConstruction(){}

//Definition of deconstructor
//
DetectorConstruction::~DetectorConstruction(){}

//Definition of Construct() method
//
G4VPhysicalVolume* DetectorConstruction::Construct(){

    //The purpose of this example is to show
    //how to build materials in Geant4.
    //
    
    //If a material is made of a single elements
    //it can be defined in a straightforward way.
    ///Example for pure iron material
    //
    G4int atomic_number = 26;
    G4double density = 7.87*g/cm3;
    G4double atomic_weight = 55.845*g/mole;
    G4Material* pureIron = new G4Material("pureIron", atomic_number, atomic_weight, density); 
    //Here are some getters from G4Material
    //
    G4cout<<pureIron->GetName()<<'\n'<<
        "density: "<<pureIron->GetDensity()/(g/cm3)<<"g/cm3"<<'\n'<<
        "number of elements: "<<pureIron->GetNumberOfElements()<<'\n'<<
        "radiation length: "<<pureIron->GetRadlen()<<"mm"<<'\n'<<
        "nucl. int. length: "<<pureIron->GetNuclearInterLength()<<"mm"<<'\n'<<
        "e- per volume: "<<pureIron->GetTotNbOfElectPerVolume()<<"mm3"<<G4endl;













    //Get nist manager and G4_WATER material
    //
    G4NistManager* nist = G4NistManager::Instance();   
    G4Material* fe = nist->FindOrBuildMaterial("G4_Fe");
    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");
    
    //World (box)
    //
    G4Box* solidWorld = new G4Box("World", 1.5*m, 1.5*m, 1.5*m);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, air, "World");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0,               //no rotation
                                                     G4ThreeVector(), //at (0,0,0)
                                                     logicWorld,      //its logical volume
                                                     "World",         //its name
                                                     0,               //its mother volume
                                                     false,           //no boolean operation
                                                     0,               //its copy number
                                                     false);          //overlaps checking

    //Box of absorber
    //
    G4Box* solidBox = new G4Box("Box", 0.5*m, 0.5*m, 0.5*m);
    G4LogicalVolume* logicBox = new G4LogicalVolume(solidBox, fe, "Box");
                                   new G4PVPlacement(0,               //no rotation
                                                     G4ThreeVector(), //at (0,0,0)
                                                     logicBox,        //its logical volume
                                                     "World",         //its name
                                                     logicWorld,      //its mother volume
                                                     false,           //no boolean operation
                                                     0,               //its copy number
                                                     false);          //overlaps checking

    return physWorld;

}

//**************************************************
