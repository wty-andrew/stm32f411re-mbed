#ifndef MBED_MOTORDRIVER_H
#define MBED_MOTORDRIVER_H

#include <mbed.h>

#include "Motor.h"

class MotorDriver {
public:
  MotorDriver(
    PinName INA1,
    PinName INB1,
    PinName PWM1,
    PinName EN1DIAG1,
    PinName CS1,
    PinName INA2,
    PinName INB2,
    PinName PWM2,
    PinName EN2DIAG2,
    PinName CS2);

  static MotorDriver DualVNH5019();

  static MotorDriver MonsterMotoShield();

  void set_speeds(float left_speed, float right_speed);

  void set_brakes(float left_brake, float right_brake);

  void stop();

private:
  Motor left_motor_;
  Motor right_motor_;
};

#endif  // MBED_MOTORDRIVER_H
