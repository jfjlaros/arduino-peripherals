#include "photoresistor.h"


PhotoResistor::PhotoResistor(int pin) {
  pinMode(pin, INPUT_PULLUP);
  _pin = pin;
}

int PhotoResistor::read(void) {
  return analogRead(_pin);
}
