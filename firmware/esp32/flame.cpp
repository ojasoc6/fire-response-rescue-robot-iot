#include "flame.h"

FlameSensor::FlameSensor(int digitalPin) : pin(digitalPin) {}

void FlameSensor::begin() {
  pinMode(pin, INPUT_PULLUP);
}

bool FlameSensor::isFlameDetected() {
  return digitalRead(pin) == LOW;
}
