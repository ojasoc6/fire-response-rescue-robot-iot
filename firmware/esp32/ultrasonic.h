#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

struct UltrasonicReadings {
  float front;
  float left;
  float right;
};

class UltrasonicSensors {
private:
  int trigFront, echoFront;
  int trigLeft, echoLeft;
  int trigRight, echoRight;

  float measureSingle(int trigPin, int echoPin);

public:
  UltrasonicSensors(int tf, int ef, int tl, int el, int tr = -1, int er = -1);
  void begin();
  UltrasonicReadings readAll();
};

#endif
