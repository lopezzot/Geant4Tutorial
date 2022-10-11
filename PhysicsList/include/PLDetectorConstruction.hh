//**************************************************
// \file PLDetectorConstruction.hh
// \brief: Declaration of PLDetectorConstruction 
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim) 
//          @lopezzot
// \start date: 10 October 2022
//**************************************************

#ifndef PLDetectorConstruction_h
#define PLDetectorConstruction_h 1

//Includers from Geant4
//
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

//Forward declaration from Geant4
//
class G4VPhysicalVolume;
class G4LogicalVolume;

class PLDetectorConstruction : public G4VUserDetectorConstruction {

    public:
        PLDetectorConstruction();
        ~PLDetectorConstruction() override;

        G4VPhysicalVolume* Construct() override; 

};

#endif //PLDetectorConstruction_h 1

//**************************************************
