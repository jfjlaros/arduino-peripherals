#ifndef PhotoResistor_h
#define PhotoResistor_h

#include <Arduino.h>


class PhotoResistor {
  public:
    PhotoResistor(int);
    int read(void);
    double lux(void);
  private:
    int _pin;
};

#endif
