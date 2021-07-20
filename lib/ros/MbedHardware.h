/*
 * MbedHardware
 *
 *  Created on: Aug 17, 2011
 *      Author: nucho
 */

#ifndef ROS_MBED_HARDWARE_H_
#define ROS_MBED_HARDWARE_H_

#include <chrono>
#include <mbed.h>

#include "MyBuffer.h"

class MbedHardware {
  public:
    MbedHardware(PinName tx, PinName rx, long baud = 57600, uint32_t buf_size = 256)
      : iostream(tx, rx), baud_(baud), buffer_(buf_size) {
      iostream.attach(callback(this, &MbedHardware::rxIrq), SerialBase::RxIrq);
        t.start();
    }

    MbedHardware() : MbedHardware(USBTX, USBRX) {}

    ~MbedHardware() {
        iostream.attach(NULL, SerialBase::RxIrq);
    }

    void setBaud(long baud){
      this->baud_= baud;
    }

    int getBaud(){return baud_;}

    void init(){
        iostream.baud(baud_);
    }

    int read(){
        return buffer_.available() ? buffer_.get() : -1;
    };

    void write(uint8_t* data, int length) {
        iostream.write(data, length);
        iostream.sync();
    }

    unsigned long time() {
        return chrono::duration_cast<chrono::milliseconds>(t.elapsed_time()).count();
    }

protected:
    UnbufferedSerial iostream;
    long baud_;
    Timer t;
    MyBuffer<char> buffer_;

private:
    void rxIrq() {
        char c;

        if (iostream.read(&c, 1))  {
            buffer_.put(c);
        }
    }
};


#endif /* ROS_MBED_HARDWARE_H_ */
