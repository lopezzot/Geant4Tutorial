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
    ///Example for pure iron material.
    //
    G4int atomic_number = 26;
    G4double density = 7.87*g/cm3;
    G4double atomic_weight = 55.845*g/mole;
    G4Material* pureIron = new G4Material("pureIron", atomic_number, atomic_weight, density); 
    //Here are some getters from G4Material
    //
    G4cout<<pureIron->GetName()<<"->"<<'\n'<<
        "density: "<<pureIron->GetDensity()/(g/cm3)<<" g/cm3"<<'\n'<<
        "number of elements: "<<pureIron->GetNumberOfElements()<<'\n'<<
        "radiation length: "<<pureIron->GetRadlen()<<" mm"<<'\n'<<
        "nucl. int. length: "<<pureIron->GetNuclearInterLength()<<" mm"<<'\n'<<
        "e- per volume: "<<pureIron->GetTotNbOfElectPerVolume()<<" mm3"<<G4endl;

    //If the building block of a material
    //is a molecule (istead of a single element)
    //one has to Add each element to the material.
    //Example for water material.
    //
    G4int ncomp = 2; //water is made of idrogen and oxigen
    G4double water_density = 1.0*g/cm3;
    G4Material* H2O = new G4Material("Water",water_density,ncomp); 
    G4double a = 1.01*g/mole;
    G4int z = 1;
    G4Element* elH = new G4Element("Hydrogen","H",z,a);
    a = 16.00*g/mole;
    z = 8;
    G4int nAtoms; 
    G4Element* elO = new G4Element("Oxygen","O",z,a);
    H2O->AddElement(elH, nAtoms=2);
    H2O->AddElement(elO, nAtoms=1);

    //It is also possible to create mixtures (alloys)
    //of both materials and elements.
    //Example simplified air material, i.e. mixture of 78% nitrogen
    //21% oxigen and 1% argon (volume fractions).
    //
    G4Element* elN = new G4Element("Nitrogen","N",7,14.01*g/mole);
    G4Element* elAr = new G4Element("Argon","Ar",18,39.95*g/mole);
    
    G4Material* O2 = new G4Material("02",0.0014*g/cm3,1);
    O2->AddElement(elO, nAtoms=2);
    G4Material* N2 = new G4Material("N2",0.0012*g/cm3,1);
    N2->AddElement(elN, nAtoms=2);
    G4double fracMass;
    G4Material* air = new G4Material("Air",0.0012*g/cm3,3);
    air->AddMaterial(O2, fracMass=75.5*perCent); //molar mass fractions
    air->AddMaterial(N2, fracMass=23.2*perCent);
    air->AddElement(elAr, fracMass=1.3*perCent);

    //Elements are treated by default
    //according to the natural isotope abundance.
    //It is possible to define an element with non-natural
    //abundance by assigning a list of G4Isotope istances.
    //Example with nuclear fuel (UF6).
    //Create uranium 235 and 238:
    //
    G4int z_iso, a_iso;
    G4Isotope* u235 = new G4Isotope("U235",z_iso=92,a_iso=235.,235.044*g/mole);
    G4Isotope* u238 = new G4Isotope("U238",z_iso=92,a_iso=238.,238.051*g/mole);

    //Create enriched uranium
    //
    G4int u_comp;
    G4double u_abundance;
    G4Element* enrichedU = new G4Element("enrichedU","eU",u_comp=2);
    enrichedU->AddIsotope(u235,u_abundance=5.0*perCent);
    enrichedU->AddIsotope(u238,u_abundance=95.0*perCent);

    //Need fluorine
    //
    G4Element* elF = new G4Element("Fluorine","F",9,18.998*g/mole);
    
    //Make nuclear fuel (UF6)
    //
    G4Material* fuel = new G4Material("NuclearFuel",5.09*g/cm3,ncomp=2,  //mandatory arguments
                                      kStateGas,640*kelvin,1.5e7*pascal);//optional arguments
                                                                         //set to STP if not specified
    fuel->AddElement(elF,6);
    fuel->AddElement(enrichedU,1);

    //Most of the materials you might want are already defined for you.
    //All elements with natural isotopic abundance already defined too.
    //Geant4 uses the NIST database, providing the best accuracy
    //for major parameters (density, iosotopic composition, ...).
    //You can access them via the G4NistManager.
    //Example.
    //

    





    //Get nist manager and G4_WATER material
    //
    G4NistManager* nist = G4NistManager::Instance();   
    G4Material* fe = nist->FindOrBuildMaterial("G4_Fe");
    //G4Material* air = nist->FindOrBuildMaterial("G4_AIR");
    
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
    G4LogicalVolume* logicBox = new G4LogicalVolume(solidBox, fuel, "Box");
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
