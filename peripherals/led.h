#ifndef __LED_H__
#define __LED_H__

#include "output.h"


class LED : public Output {
  using Output::Output;
  public:
    void pulse(int, int),
         signal(byte);
};

#endif
