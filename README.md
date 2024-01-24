# Kaleidoscope on Playdate

WIP funky visuals driven by the Playdate's crank.

## Development

Requires the Playdate SDK. See https://play.date/dev

To build for the Playdate Simulator:

```bash
# Clean up and remake the build directory
rm -rf build;
mkdir build;
cd build;
# CMake with option to generate `clangd` LSP configuration
cmake  -DCMAKE_EXPORT_COMPILE_COMMANDS=1  ..;
# Build C project
make;
cd ..
# Pack project into `.pdx` Playdate bundle
pdc Source;
```

To build for Playdate device (not yet tested):

```bash
# From the project directory
rm *.pdx
rm -rf build_for_device;
mkdir build_for_device;
cd build_for_device;
cmake -DCMAKE_TOOLCHAIN_FILE=$PLAYDATE_SDK_PATH/C_API/buildsupport/arm.cmake ..;
make
cd ..
```
