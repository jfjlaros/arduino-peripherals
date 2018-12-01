#include "output.h"


/**
 * Constructor.
 *
 * @arg {byte} pin - Output pin.
 * @arg {bool} invert - Reverse output behaviour.
 */
Output::Output(byte pin, bool invert) {
  _pin = pin;
  _invert = invert;

  pinMode(_pin, OUTPUT);
  off();
}

/**
 * Write an analogue value.
 *
 * @arg {byte} value - Value.
 */
void Output::analogWrite(byte value) {
  if (_invert) {
    ::analogWrite(_pin, 0xff - value);
  }
  else {
    ::analogWrite(_pin, value);
  }
}

/**
 * Write a digital value.
 *
 * @arg {bool} value - Value.
 */
void Output::digitalWrite(bool value) {
  ::digitalWrite(_pin, value ^ _invert);
}

/**
 * Write HIGH.
 */
void Output::on(void) {
  digitalWrite(HIGH);
}

/**
 * Write LOW.
 */
void Output::off(void) {
  digitalWrite(LOW);
}
