#include "input.h"


/**
 * Constructor.
 *
 * @arg {byte} pin - Input pin.
 * @arg {bool} invert - Reverse input behaviour.
 * @arg {bool} pullUp - Use internal pull up resistor.
 */
Input::Input(byte pin, bool invert, bool pullUp) {
  _pin = pin;
  _invert = invert;
  _pullUp = pullUp;

  if (pullUp) {
    pinMode(_pin, INPUT_PULLUP);
  }
  else {
    pinMode(_pin, INPUT);
  }
}

/**
 * Read an analogue value.
 *
 * @return {byte} - Value.
 */
byte Input::analogRead(void) {
  if (_invert) {
    return 1023 - ::analogRead(_pin);
  }
  return ::analogRead(_pin);
}

/**
 * Read a digital value.
 *
 * @return {bool} - Value.
 */
bool Input::digitalRead(void) {
  return ::digitalRead(_pin) ^ _invert;
}
