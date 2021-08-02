#include "Motor.h"

static float clamp(float value, float lower, float upper) {
  return (value < lower) ? lower : (value > upper) ? upper : value;
}

Motor::Motor(PinName INA, PinName INB, PinName PWM, PinName ENDIAG, PinName CS)
    : INA_(INA), INB_(INB), PWM_(PWM), ENDIAG_(ENDIAG), CS_(CS) {
  enable();
  PWM_.period_us(100);  // 10 kHz
  stop();
}

void Motor::set_speed(float speed) {
  if (speed == 0.0) {
    INA_ = 0;
    INB_ = 0;
  } else if (speed < 0) {
    INA_ = 0;
    INB_ = 1;
  } else {
    INA_ = 1;
    INB_ = 0;
  }
  PWM_ = clamp(abs(speed), 0.0, 1.0);
}

void Motor::stop() { set_speed(0.0); }

void Motor::brake(float power) {
  INA_ = 0;
  INB_ = 0;
  PWM_ = clamp(abs(power), 0.0, 1.0);
}

// see https://forum.sparkfun.com/viewtopic.php?t=38903
float Motor::get_current_mA() {
  // from datasheet, Iout / Isense = 11370, Rsense = 1.5K
  // => Iout = (Vsense / Rsense) * 11370 = (ain * 3.3V / 1.5KΩ) * 11370 = ain * 25.014 mA
  return CS_.read() * 25;
}

bool Motor::get_fault() { return !ENDIAG_.read(); }

void Motor::disable() {
  ENDIAG_.output();
  ENDIAG_.write(0);
}

void Motor::enable() {
  ENDIAG_.input();
  ENDIAG_.mode(PullUp);
}
