#include "Encoder.h"

Encoder::Encoder(PinName pinA, PinName pinB) : pinA_(pinA), pinB_(pinB) {
  pinA_.rise(callback(this, &Encoder::update));
};

int Encoder::ticks() { return ticks_; }

void Encoder::update() { ticks_ += pinB_.read() ? -1 : 1; }
