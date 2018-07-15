#ifndef Thermistor_h
#define Thermistor_h

#include <Arduino.h>


class Thermistor {
  public:
    Thermistor(int, double, bool);
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
