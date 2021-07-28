#include "PID.h"

static float clamp(float value, float lower, float upper) {
  return (value < lower) ? lower : (value > upper) ? upper : value;
}

PID::PID(float Kp, float Ki, float Kd) : Kp_(Kp), Ki_(Ki), Kd_(Kd) {}

void PID::set_proportional_gain(float Kp) {
  Kp_ = Kp;
}

void PID::set_integral_gain(float Ki) {
  Ki_ = Ki;
}

void PID::set_derivative_gain(float Kd) {
  Kd_ = Kd;
}

void PID::set_parameters(float Kp, float Ki, float Kd) {
  Kp_ = Kp;
  Ki_ = Ki;
  Kd_ = Kd;
}

void PID::set_output_limits(float min, float max) {
  output_min_ = min;
  output_max_ = max;
}

void PID::set_setpoint(float value) {
  setpoint_ = value;
}

float PID::compute(float input, float dt) {
  float error = setpoint_ - input;

  float proportional_term = Kp_ * error;
  float integral_term = clamp(prev_integral_term_ + Ki_ * error * dt, output_min_, output_max_);
  float derivative_term = Kd_ * (prev_input_ - input) / dt; // derivative on measurement

  float output =
    clamp(proportional_term + integral_term + derivative_term, output_min_, output_max_);

  prev_input_ = input;
  prev_integral_term_ = integral_term;

  return output;
}

void PID::reset() {
  setpoint_ = 0;
  prev_input_ = 0;
  prev_integral_term_ = 0;
}
