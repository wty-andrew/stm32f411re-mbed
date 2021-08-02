#ifndef MBED_ENCODER_H
#define MBED_ENCODER_H

#include <mbed.h>

class Encoder {
public:
  Encoder(PinName pinA, PinName pinB);

  int ticks();

  void update();

  void reset();

private:
  InterruptIn pinA_;
  DigitalIn pinB_;

  volatile int ticks_;
};

#endif  // MBED_ENCODER_H
