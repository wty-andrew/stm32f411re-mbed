#include "MotorDriver.h"

MotorDriver::MotorDriver(
  PinName INA1,
  PinName INB1,
  PinName PWM1,
  PinName EN1DIAG1,
  PinName CS1,
  PinName INA2,
  PinName INB2,
  PinName PWM2,
  PinName EN2DIAG2,
  PinName CS2)
    : left_motor_(INA1, INB1, PWM1, EN1DIAG1, CS1), right_motor_(INA2, INB2, PWM2, EN2DIAG2, CS2) {}

MotorDriver MotorDriver::DualVNH5019() {
  return MotorDriver(D2, D4, D9, D6, A0, D7, D8, D10, D12, A1);
}

MotorDriver MotorDriver::MonsterMotoShield() {
  return MotorDriver(D7, D8, D5, A0, A2, D4, D9, D6, A1, A3);
}

void MotorDriver::set_speeds(float left_speed, float right_speed) {
  left_motor_.set_speed(left_speed);
  right_motor_.set_speed(right_speed);
}

void MotorDriver::set_brakes(float left_power, float right_power) {
  left_motor_.brake(left_power);
  right_motor_.brake(right_power);
}

void MotorDriver::stop() {
  left_motor_.stop();
  right_motor_.stop();
}
