# Pico SOS Code

Simple C code to flash the LED on the Raspberry Pi Pico an SOS pattern.

## Requirements
- Raspberry Pi Pico
- [Pico SDK](https://github.com/raspberrypi/pico-sdk)
- CMake
- ninja
- GNU Arm Embedded Toolchain (`brew install --cask gcc-arm-embedded` on macOS)

## Setup

1. Clone the Pico SDK:
2. Set the `PICO_SDK_PATH` to the path of the cloned SDK repo.
3. Run the following commands in your terminal:

```bash
mkdir build
cd build
cmake -G Ninja .. -DPICO_BOARD=pico ..
ninja
```

4. Unplug the Pico, hold down the BOOTSEL button, and plug it back in to mount it as a USB drive.
5. Copy the generated `build/pico-sos.uf2` to the mounted drive.
