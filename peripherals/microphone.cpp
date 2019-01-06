#include "microphone.h"


/**
 * Determine the sound level by analysing a number of samples.
 *
 * @arg {unsigned int} samples - Number of samples.
 *
 * @return {unsigned int} - Sound level.
 */
unsigned int Microphone::soundLevel(unsigned int samples) {
  unsigned int max = 0,
               min = -1,
               data,
               i;

  for (i = 0; i < samples; i++) {
    data = analogRead();

    if (data > max) {
      max = data;
    }
    if (data < min) {
      min = data;
    }
  }

  return max - min;
}
