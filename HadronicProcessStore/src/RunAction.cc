//**************************************************
// \file RunAction.cc
// \brief: implementation of RunAction class
// \author: Lorenzo Pezzotti (CERN EP-SFT-sim)
//          @lopezzot
// \start date: 24 October 2023
//**************************************************

// Includers from project files
//
#include "RunAction.hh"

// Includers from Geant4
//
#include "G4Element.hh"
#include "G4ElementVector.hh"
#include "G4HadronicProcessStore.hh"
#include "G4Material.hh"
#include "G4Neutron.hh"
#include "G4NistManager.hh"
#include "G4ProcessTable.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4VProcess.hh"

// Constructor and de-constructor
//
RunAction::RunAction() : G4UserRunAction() {}

RunAction::~RunAction() {}

// BeginOfRunAction method
//
void RunAction::BeginOfRunAction(const G4Run* /*run*/) {}

// EndOfRunAction
//
void RunAction::EndOfRunAction(const G4Run* /*run*/)
{
  if (IsMaster()) {  // note: removing IsMaster() lead to segmentation fault

    // This part is similar to examples/extended/Hadr03 (G4-11.1)

    // Dump a process info, get the process from the ProcessTable
    //
    G4ProcessTable* processTable = G4ProcessTable::GetProcessTable();
    G4VProcess* process = processTable->FindProcess("protonInelastic", G4Proton::Proton());
    G4cout << "Showing Info for process: " << process->GetProcessName() << G4endl;
    process->DumpInfo();

    // Use the G4HadronicProcessStore to access hadronic total cross sections
    // without simulation
    //
    G4cout << "Computing cross section from HadronicProcessStore" << G4endl;
    G4HadronicProcessStore* hadstore = G4HadronicProcessStore::Instance();
    G4Material* matPb = G4NistManager::Instance()->FindOrBuildMaterial("G4_Pb");
    const G4Element* element = matPb->GetElement(0);
    G4double InelXS1 =
      hadstore->GetInelasticCrossSectionPerAtom(G4Proton::Proton(), 10. * GeV, element, matPb);
    G4cout << "InelXS 10 GeV p on Pb " << G4BestUnit(InelXS1, "Surface") << G4endl;
    G4double InelXS2 =
      hadstore->GetInelasticCrossSectionPerAtom(G4Neutron::Neutron(), 10. * GeV, element, matPb);
    G4cout << "InelXS 10 GeV n on Pb " << G4BestUnit(InelXS2, "Surface") << G4endl;
  }
}

//**************************************************
