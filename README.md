PlatformIO project for STM32F411RE (Mbed OS 6 + ROS serial)

# Build & Upload
- Run `PlatformIO: Upload` command

# Run
- `rosrun rosserial_python serial_node.py _port:=<port-name>`

# Notes
- Regenerate ros lib (for custom message types)
  - Install `rosserial_mbed`: `sudo apt install ros-noetic-rosserial-mbed`
  - Create library: `rosrun rosserial_mbed make_libraries.py <path/to/project/lib/ros>`
  - Remove `BufferedSerial` folder and `BufferedSerial.lib` (these are for Mbed OS 5)
  - Checkout `MbedHardware.h` (Contain modification for Mbed OS 6)
