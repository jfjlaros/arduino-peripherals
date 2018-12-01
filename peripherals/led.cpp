#include "led.h"

// LED blink durations.
#define LED_SHORT 100
#define LED_LONG 500


/**
 * Pulse.
 *
 * @arg {int} durationOn - LED on duration.
 * @arg {int} durationOff - LED off duration.
 */
void LED::pulse(int durationOn, int durationOff) {
  on();
  delayMicroseconds(durationOn);
  off();
  delayMicroseconds(durationOff);
}

/**
 * Convert a byte of data to a series of LED pulses.
 *
 * @arg {byte} data - Data to be converted.
 */
void LED::signal(byte data) {
  int i;

  for (i = 7; i >= 0; i--) {
    if (data & (1 << i)) {
      pulse(LED_LONG, LED_SHORT);
    }
    else {
      pulse(LED_SHORT, LED_SHORT);
    }
  }
}
