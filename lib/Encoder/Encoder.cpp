#include "Encoder.h"

Encoder::Encoder(PinName pinA, PinName pinB) : pinA_(pinA), pinB_(pinB) {
  pinA_.rise(callback(this, &Encoder::update));
  pinA_.fall(callback(this, &Encoder::update));
};

int Encoder::ticks() { return ticks_; }

void Encoder::update() {
  if (pinA_.read()) {  // rising
    ticks_ += pinB_.read() ? -1 : 1;
  } else {  // falling
    ticks_ += pinB_.read() ? 1 : -1;
  }
}

void Encoder::reset() {
  ticks_ = 0;
}
