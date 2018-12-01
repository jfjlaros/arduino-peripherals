#include "buzzer.h"


/**
 * Generate a tone with a given frequency.
 *
 * @arg {unsigned long} frequency - Frequency.
 */
void Buzzer::tone(unsigned long frequency) {
  ::tone(_pin, frequency);
}

/**
 * Turn the buzzer off.
 */
void Buzzer::noTone(void) {
  ::noTone(_pin);
  off();
}
