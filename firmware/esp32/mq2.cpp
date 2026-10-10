#include "mq2.h"

MQ2Sensor::MQ2Sensor(int analogPin, int threshold)
  : pin(analogPin), alertThreshold(threshold) {}

void MQ2Sensor::begin() {
  pinMode(pin, INPUT);
}

MQ2Readings MQ2Sensor::read() {
  MQ2Readings data;
  data.raw = analogRead(pin);
  data.voltage = (data.raw / 4095.0) * 3.3;
  data.alert = (data.raw > alertThreshold);
  return data;
}
