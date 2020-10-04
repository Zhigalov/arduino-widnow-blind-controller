#pragma once

#include <IRremote.h>
#include "pins.h"

namespace NRemote {
  IRrecv irrecv(REMOTE_CONTROL_PIN);
  decode_results remoteData;
  
  enum class ERemote {
    EMPTY,
    OTHER,
    LEFT,
    RIGHT,
    STOP
  };
  
  void setup() {
    irrecv.enableIRIn();
  }
  
  ERemote get() {
    ERemote result = ERemote::EMPTY;
    
    if (irrecv.decode(&remoteData)) {
      switch (remoteData.value) {
        case 0x6FB08F7:
          result = ERemote::LEFT;
          break;
        case 0x6FB8877:
          result = ERemote::RIGHT;
          break;
        case 0x6FBB04F:
          result = ERemote::STOP;
          break;
        default:
          result = ERemote::OTHER;
      }
      delay(100);
      irrecv.resume();
    }
    
    return result;
  }
}
