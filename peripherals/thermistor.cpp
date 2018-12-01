#include "thermistor.h"


/**
 * Constructor.
 *
 * @arg {byte} pin - Analog pin number.
 * @arg {float} resistor - Resistor value in Ohm.
 * @arg {bool} invert - Invert analogue read behaviour.
 * @arg {bool} pullUp - Pull up resistor.
 */
Thermistor::Thermistor(byte pin, float resistor, bool invert, bool pullUp)
    : Input(pin, invert, pullUp) {
  _resistor = resistor;
}

/**
 * Report the temperature in degrees Kelvin.
 *
 * Use the Steinhart–Hart equation to convert from resistance to temperature.
 *
 * @return {float} - Temperature in degrees Kelvin.
 */
float Thermistor::kelvin(void) {
  float temp;

  if (_pullUp) {
    temp = log(_resistor / (1024.0 / (float)analogRead() - 1.0));
  }
  else {
    temp = log(_resistor * (1024.0 / (float)analogRead() - 1.0));
  }

  return 1.0 / (
    0.001129148 +
    0.000234125 * temp +
    0.0000000876741 * pow(temp, 3));
}

/**
 * Report the temperature in degrees Celsius.
 *
 * @return {float} - Temperature in degrees Celsius.
 */
float Thermistor::celsius(void) {
  return kelvin() - 273.15;
}

/**
 * Report the temperature in degrees Fahrenheit.
 *
 * @return {float} - Temperature in degrees Fahrenheit.
 */
float Thermistor::fahrenheit(void) {
  return celsius() * 1.8 + 32.0;
}
