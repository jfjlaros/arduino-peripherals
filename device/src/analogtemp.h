#ifndef AnalogTemp_h
#define AnalogTemp_h

#include <Arduino.h>


class AnalogTemp {
  public:
    AnalogTemp(int, double, bool);
    int rawRead(void);
    double read(void),
           celsius(void),
           fahrenheit(void);
  private:
    int _pin;
    double _resistor;
    bool _pullup;
};

#endif
