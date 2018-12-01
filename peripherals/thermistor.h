#ifndef __THERMISTOR_H__
#define __THERMISTOR_H__

#include "input.h"


class Thermistor : public Input {
  public:
    Thermistor(void) {}
    Thermistor(byte, float, bool=false, bool=false);
    float kelvin(void),
          celsius(void),
          fahrenheit(void);
  private:
    float _resistor;
};

#endif
