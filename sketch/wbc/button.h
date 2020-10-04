#pragma once

#include "pins.h"

namespace NButton {
  enum class EButton {
    UNKNOWN,
    LEFT,
    RIGHT
  };
  
  void setup() {
    pinMode(LEFT_PIN, INPUT);
    pinMode(RIGHT_PIN, INPUT);
  }
  
  EButton get() {
    if (digitalRead(LEFT_PIN)) {
      return EButton::LEFT;
    } else if (digitalRead(RIGHT_PIN)) {
      return EButton::RIGHT;
    }
    
    return EButton::UNKNOWN;
  }
}
