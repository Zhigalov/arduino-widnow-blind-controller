#include "led.h"
#include "remote.h"
#include "button.h"
#include "motor.h"

#define QUADRANT      46080
#define INTERVAL      92160
#define STEP          1000

long int maxPosition;
long int minPosition;

void setup(){
  NLed::setup();
  NRemote::setup();
  NButton::setup();
  NMotor::setup();

  maxPosition = NMotor::current();
  minPosition = NMotor::current();
}
 
void loop(){
  switch (NButton::get()) {
    case NButton::EButton::LEFT:
      NLed::on(NLed::EColor::BLUE);
      NMotor::shiftTo(STEP);
      break;
      
    case NButton::EButton::RIGHT:
      NLed::on(NLed::EColor::BLUE);
      NMotor::shiftTo(-STEP);
      break;
      
    default:
      NLed::off();
      switch (NRemote::get()) {
        case NRemote::ERemote::LEFT:
          if (maxPosition - minPosition >= INTERVAL) {
            const auto dx = min(QUADRANT, maxPosition - NMotor::current());
            NLed::blink(dx == 0 ? NLed::EColor::RED : NLed::EColor::GREEN);
            NMotor::shiftTo(dx);
          } else {
            NLed::blink(NLed::EColor::YELLOW);  
            NMotor::shiftTo(QUADRANT);
            maxPosition += QUADRANT;
          }
          break;
        
        case NRemote::ERemote::RIGHT:
          if (maxPosition - minPosition >= INTERVAL) {
            const auto dx = -1 * min(QUADRANT, NMotor::current() - minPosition);
            NLed::blink(dx == 0 ? NLed::EColor::RED : NLed::EColor::GREEN);
            NMotor::shiftTo(dx);
          } else {
            NLed::blink(NLed::EColor::YELLOW);  
            NMotor::shiftTo(-QUADRANT);
            minPosition -= QUADRANT;
          }
          break;
          
        case NRemote::ERemote::STOP:
          NLed::blink(NLed::EColor::RED);
          NMotor::stop();
          break;

        case NRemote::ERemote::OTHER:
          NLed::blink(NLed::EColor::BLUE);
          break;
      }
  }
  if (NMotor::isRunning() && abs(NMotor::current() / 100) % 3 == 0) {
    NLed::on(NLed::EColor::GREEN);
  } else {
    NLed::off();
  }
  NMotor::run();
}
