# Geant4Tutorial
This is a messy collection of code examples and lessons for Geant4 educational purposes. It is developed according to my free time and needs, do not expect a clean environment.

## Code examples
### Basic examples
- [MWE](https://github.com/lopezzot/Geant4Tutorial/tree/main/MWE) - A Minimal Working Example using Geant4 (11.1). Only simulates (single-threaded mode) a block or iron and shoots particles into it.
- [Material](https://github.com/lopezzot/Geant4Tutorial/tree/main/Material) - This example shows how to define materials in Geant4 and retrieve materials information. It illustrates the usage of the `G4NistManager` as well.
- [Analysis](https://github.com/lopezzot/Geant4Tutorial/tree/main/Analysis) - This example shows how to use the `G4Analysis` suite to save data with the `G4AnalysisManager`.
### Advanced examples
- [TrackInformation](https://github.com/lopezzot/Geant4Tutorial/tree/main/TrackInformation) - This example shows how to add custom information to tracks. It uses the `G4VUserTrackInformation` class and the track `SetUserInformation` method. Specifically, it adds to each track the parent PDGID and illustrates how $\mu^-$ produced in hadronic showers come from $\pi^-$, $K^-$ and $K_L^0$ decays.
- [FTFTunings](https://github.com/lopezzot/Geant4Tutorial/tree/main/FTFTunings) - This example shows how to use alternative sets of parameters for the FTF model as introduced in Geant4-11.1.0.
- [HadronicProcessStore](https://github.com/lopezzot/Geant4Tutorial/tree/main/HadronicProcessStore) - This example shows how to use the `G4HadronicProcessStore` to retrieve total hadronic cross-sections.
- [RadioactiveDecay](https://github.com/lopezzot/Geant4Tutorial/tree/main/RadioactiveDecay) - This example shows how to register the `G4RadioactiveDecayPhysics` constructor and simulate a radioactive source of cobalt 60 at rest.
- [Radioactivation](https://github.com/lopezzot/Geant4Tutorial/tree/main/Radioactivation) - This example shows how to register the `G4Radioactivation` process to use radioactive decay process in bias mode. It shows also how to bias radioactive decay with UI command in the macro card.
- [HadronicPhysicsBiasing](https://github.com/lopezzot/Geant4Tutorial/tree/main/HadronicPhysicsBiasing) - This example shows how to bias hadronic physics cross-sections using the built-in hadronic method `BiasCrossSectionByFactor()`. The muon lepto-nuclear process is used as an example.
- [ApplyXSFactor](https://github.com/lopezzot/Geant4Tutorial/tree/main/ApplyFactorXS) - This example shows how to scale hadronic cross-sections using the `SetXSFactor` methods of `G4HadronicParameters` with a maximum absolute scaling allowed of 20%.
## Lessons (slides)
All slides are available [here](https://cernbox.cern.ch/s/WnpzvYfihfOUxPO).

- :open_file_folder: <em>ExamplesDocumentation.pdf</em> - Topics: Geant4 installation, building basic examples, overview of extended and advanced examples, official documentation and user support.
- :open_file_folder: <em>Materials.pdf</em> - Topics: materials in Geant4, definition of materials, the the G4NistManager.
- :open_file_folder: <em>Analysis.pdf</em> - Topics: data persistence in Geant4, g4analysis, the G4AnalysisManager.
- :open_file_folder: <em>HadronicPhysicsI.pdf</em> - Topics: final state models and cross sections, hadronic physics framework, capture at rest, neutron physics, hadronic physics in reference physics lists.
- :open_file_folder: <em>HadronicPhysicsII.pdf</em> - Topics: high-precision neutron treatment (NEUTRON_HP), nuclides and radioactive decay, nucleus-nucleus, lepto-nuclear and gamma-nuclear interactions, hadronic physics biasing, hadronic physics validation.
- :open_file_folder: <em>ChoosingPhysicsList.pdf</em> - Topics: recap of physics lists (reference physics list, modular physics list, naming conventions, using reference physics lists), some reference physics lists, cuts, validation and geant-val with examples.
