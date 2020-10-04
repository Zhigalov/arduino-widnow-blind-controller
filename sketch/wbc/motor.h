#pragma once

#include <AccelStepper.h>
#include "pins.h"

namespace NMotor {
  AccelStepper stepper(8 /*half-step*/, MOTOR_PIN_1, MOTOR_PIN_3, MOTOR_PIN_2, MOTOR_PIN_4);
  
  void setup() {
    stepper.setMaxSpeed(1000.0);    // steps per second
    stepper.setAcceleration(500.0); // on step per second
  }
  
  void shiftTo(const long dx) {
    stepper.moveTo(stepper.currentPosition() + dx);
  }
  
  void run() {
    stepper.run();
  }
  
  void stop() {
    stepper.stop();
  }
  
  long current() {
    return stepper.currentPosition();
  }

  bool isRunning() {
    return stepper.isRunning();
  }
}
