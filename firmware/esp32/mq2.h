#ifndef MQ2_H
#define MQ2_H

#include <Arduino.h>

struct MQ2Readings {
  int raw;
  float voltage;
  bool alert;
};

class MQ2Sensor {
private:
  int pin;
  int alertThreshold;

public:
  MQ2Sensor(int analogPin, int threshold = 1200);
  void begin();
  MQ2Readings read();
};

#endif
