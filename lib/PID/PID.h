#ifndef PID_H
#define PID_H

#include <limits>

class PID {
public:
  PID(float Kp, float Ki, float Kd);

  void set_proportional_gain(float Kp);

  void set_integral_gain(float Ki);

  void set_derivative_gain(float Kd);

  void set_parameters(float Kp, float Ki, float Kd);

  void set_output_limits(float min, float max);

  void set_setpoint(float value);

  float compute(float input, float dt);

  void reset();

private:
  float Kp_;
  float Ki_;
  float Kd_;
  float output_min_ = output_min_ = std::numeric_limits<float>::min();
  float output_max_ = output_max_ = std::numeric_limits<float>::max();

  float setpoint_ = 0;
  float prev_input_ = 0;
  float prev_integral_term_ = 0;
};

#endif  // PID_H
