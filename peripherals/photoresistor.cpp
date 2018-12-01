#include "photoresistor.h"


PhotoResistor::PhotoResistor(int pin) {
  _pin = pin;

  pinMode(_pin, INPUT_PULLUP);
}

int PhotoResistor::read(void) {
  return analogRead(_pin);
}

byte PhotoResistor::percentage(void) {
  return 100 - (byte)(read() * 100 / 1023);
}
