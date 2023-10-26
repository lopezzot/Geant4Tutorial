//**************************************************
// \file DetectorConstruction.hh
// \brief: Declaration of DetectorConstruction
//         class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 24 October 2023
//**************************************************

#ifndef DetectorConstruction_h
#  define DetectorConstruction_h 1

// Includers from Geant4
//
#  include "G4VUserDetectorConstruction.hh"
#  include "globals.hh"

// Forward declaration from Geant4
//
class G4VPhysicalVolume;
class G4LogicalVolume;

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction();
    ~DetectorConstruction() override;

    G4VPhysicalVolume* Construct() override;
};

#endif  // DetectorConstruction_h 1

//**************************************************
