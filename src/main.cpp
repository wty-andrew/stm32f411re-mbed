#include <mbed.h>
#include <ros.h>
#include <std_msgs/Empty.h>

ros::NodeHandle nh;

DigitalOut led(LED1);

void toggleLED(const std_msgs::Empty& msg) {
  led = !led;
}

ros::Subscriber<std_msgs::Empty> sub("toggle_led", &toggleLED);

int main() {
  nh.initNode();
  nh.subscribe(sub);

  while (1) {
    nh.spinOnce();
    ThisThread::sleep_for(1ms);
  }
}
