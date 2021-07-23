#ifndef MBED_MOTOR_H
#define MBED_MOTOR_H

#include <mbed.h>

class Motor {
public:
  Motor(PinName INA, PinName INB, PinName PWM, PinName ENDIAG, PinName CS);

  void set_speed(float speed);  // -1.0 ~ 1.0

  void stop();

  void brake(float brake);

  float get_current_mA();

  bool get_fault();

  void disable();

  void enable();

private:
  DigitalOut INA_;
  DigitalOut INB_;
  PwmOut PWM_;
  DigitalInOut ENDIAG_;
  AnalogIn CS_;
};

#endif  // MBED_MOTOR_H
