#include "Motor.h"
#include "Encoder.h"

#include <mbed.h>

#include <chrono>

BufferedSerial pc(USBTX, USBRX);

Motor motor(D2, D4, D9, D6, A0);
Encoder encoder(D3, D5);

Timer timer;

int get_elapsed_time_ms() {
  return chrono::duration_cast<chrono::duration<int, milli>>(timer.elapsed_time()).count();
}

int main() {
  printf("+/- : increase/decrease speed by 10%%\n");
  printf("s : stop\n");

  timer.start();
  int last_update = get_elapsed_time_ms();
  int last_ticks = encoder.ticks();

  float speed = 0;
  while (1) {
    /* print ticks info every second */
    int now = get_elapsed_time_ms();
    if (now - last_update > 1000) {
      int ticks = encoder.ticks();
      printf("Ticks: %d, Diff: %d\n", ticks, ticks - last_ticks);
      last_ticks = ticks;
      last_update = now;
    }

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
