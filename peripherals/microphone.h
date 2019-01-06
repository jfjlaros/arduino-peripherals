#ifndef __MICROPHONE_H__
#define __MICROPHONE_H__

#include "input.h"


class Microphone : public Input {
  using Input::Input;
  public:
    unsigned int soundLevel(unsigned int);
};

#endif
