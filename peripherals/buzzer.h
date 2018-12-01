#ifndef __BUZZER_H__
#define __BUZZER_H__

#include "output.h"


class Buzzer : public Output {
  using Output::Output;
  public:
    void noTone(void);
    void tone(unsigned long);
};

#endif
