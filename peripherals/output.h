#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include <Arduino.h>


class Output {
  public:
    Output(void) {}
    Output(byte, bool=false);
    void analogWrite(byte),
         digitalWrite(bool),
         on(void),
         off(void);
  protected:
    byte _pin;
  private:
    bool _invert;
};

#endif
