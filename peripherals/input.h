#ifndef __INPUT_H__
#define __INPUT_H__

#include <Arduino.h>


class Input {
  public:
    Input(void) {}
    Input(byte, bool=false, bool=false);
    byte analogRead(void),
         digitalRead(void);
  protected:
    byte _pin;
    bool _pullUp;
  private:
    bool _invert;
};

#endif
