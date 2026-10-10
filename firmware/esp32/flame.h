#ifndef FLAME_H
#define FLAME_H

#include <Arduino.h>

class FlameSensor {
private:
  int pin;

public:
  FlameSensor(int digitalPin);
  void begin();
  bool isFlameDetected();
};

#endif
