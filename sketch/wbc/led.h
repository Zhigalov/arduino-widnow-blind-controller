#pragma once

#include "pins.h"

namespace NLed {
  enum class EColor {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    CYAN
  };
  
  void setup() {
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
  }
  
  void _on(const int red, const int green, const int blue) {
    digitalWrite(RED_PIN, red);
    digitalWrite(GREEN_PIN, green);
    digitalWrite(BLUE_PIN, blue);
  }
  
  void on(const EColor color) {
    switch (color) {
      case EColor::RED:
        _on(1, 0, 0);
        break;
      
      case EColor::GREEN:
        _on(0, 1, 0);
        break;
        
      case EColor::BLUE:
        _on(0, 0, 1);
        break;
        
      case EColor::YELLOW:
        _on(1, 1, 0);
        break;
        
      case EColor::CYAN:
        _on(0, 1, 1);
        break;
        
      default:
        _on(1, 1, 1);
        break;
    }
  }
  
  void off() {
    _on(0, 0, 0);
  }
  
  void blink(const EColor color) {
    on(color);
    delay(50);
    off();
  }
}
