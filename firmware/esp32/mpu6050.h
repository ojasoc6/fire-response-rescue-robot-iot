#ifndef MPU6050_H
#define MPU6050_H

#include <Arduino.h>
#include <Wire.h>

struct MPUReadings {
  float ax;
  float ay;
  float az;
  bool tilt;
};

class MPUSensor {
private:
  uint8_t addr;
  float tiltThreshold;

public:
  MPUSensor(uint8_t i2cAddress = 0x68, float threshold = 0.5);
  bool begin(int sdaPin = 21, int sclPin = 22);
  MPUReadings read();
};

#endif
