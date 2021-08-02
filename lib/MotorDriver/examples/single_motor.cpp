#include "Motor.h"

#include <mbed.h>

BufferedSerial pc(USBTX, USBRX);

Motor motor(D2, D4, D9, D6, A0);

int main() {
  printf("+/- : increase/decrease speed by 10%%\n");
  printf("s : stop\n");

  float speed = 0;
  while (1) {
    if (pc.readable()) {
      char c;
      pc.read(&c, sizeof(c));

      switch (c) {
        case '+':
          speed = min(1.0, speed + 0.1);
          motor.set_speed(speed);
          printf("Speed: %.1f\n", speed);
          break;

        case '-':
          speed = max(-1.0, speed - 0.1);
          motor.set_speed(speed);
          printf("Speed: %.1f\n", speed);
          break;

        case 's':
          speed = 0;
          motor.stop();
          printf("Stop\n");

        default:
          break;
      }
    }
  }
}
