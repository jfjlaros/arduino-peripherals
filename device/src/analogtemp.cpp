#include "analogtemp.h"


/**
 * Constructor.
 *
 * @arg {int} pin - Analog pin number.
 * @arg {double} resistor - Resistor value in Ohms.
 * @arg {bool} pullup - Pull up resistor.
 */
AnalogTemp::AnalogTemp(int pin, double resistor, bool pullup) {
  _pin = pin;
  _resistor = resistor;
  _pullup = pullup;

  if (_pullup) {
    pinMode(pin, INPUT_PULLUP);
  }
  else {
    pinMode(pin, INPUT);
  }
}

int AnalogTemp::rawRead(void) {
  return analogRead(_pin);
}

/**
 * Report the temperature in degrees Kelvin.
 *
 * Use the Steinhart–Hart equation to convert from resistance to temperature.
 *
 * @return {double} - Temperature in degrees Kelvin.
 */
double AnalogTemp::read(void) {
  double temp;

  if (_pullup) {
    temp = log(_resistor / (1024.0 / rawRead() - 1.0));
  }
  else {
    temp = log(_resistor * (1024.0 / rawRead() - 1.0));
  }

  return 1.0 / (
    0.001129148 +
    0.000234125 * temp +
    0.0000000876741 * pow(temp, 3));
}

double AnalogTemp::celsius(void) {
  return read() - 273.15;
}

double AnalogTemp::fahrenheit(void) {
  return (read() - 273.15) * 1.8 + 32.0;
}
