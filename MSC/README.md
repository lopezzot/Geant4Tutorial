### Build, compile and execute on Mac/Linux
1. git clone the repo
   ```sh
   git clone https://github.com/lopezzot/Geant4Tutorial.git
   ```
2. source Geant4 env
   ```sh
   source /relative_path_to/geant4-install/bin/geant4.sh
   ```
3. build directory, cmake and make
   ```sh
   mkdir build; cd build
   cmake -DGeant4_DIR=/absolute_path_to/geant4-install/lib/Geant4/ relative_path_to/Geant4Tutorial/MWE/
   make
   ```
4. execute with visualization
   ```sh
   ./MWE
   ```
5. or, execute with macro card
   ```sh
   ./MWE run.mac
   ```
