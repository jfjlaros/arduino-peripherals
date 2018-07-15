#include "photoresistor.h"


PhotoResistor::PhotoResistor(int pin) {
  pinMode(pin, INPUT_PULLUP);
  _pin = pin;
}

int PhotoResistor::read(void) {
  return analogRead(_pin);
}

double PhotoResistor::lux(void) {
  // TODO: Fix this formula.
  return pow(10, (double)(1023 - read()) / 1024.0);
}
