#include "mpu6050.h"

MPUSensor::MPUSensor(uint8_t i2cAddress, float threshold)
  : addr(i2cAddress), tiltThreshold(threshold) {}

bool MPUSensor::begin(int sdaPin, int sclPin) {
  Wire.begin(sdaPin, sclPin);
  Wire.beginTransmission(addr);
  Wire.write(0x6B); // Power management register
  Wire.write(0);    // Wake up
  return (Wire.endTransmission() == 0);
}

MPUReadings MPUSensor::read() {
  MPUReadings data = {0.0, 0.0, 1.0, false};

  Wire.beginTransmission(addr);
  Wire.write(0x3B); // Starting register for accelerometer
  if (Wire.endTransmission(false) != 0) {
    return data;
  }

  if (Wire.requestFrom(addr, (uint8_t)6, (uint8_t)true) == 6) {
    int16_t rawX = Wire.read() << 8 | Wire.read();
    int16_t rawY = Wire.read() << 8 | Wire.read();
    int16_t rawZ = Wire.read() << 8 | Wire.read();

    data.ax = rawX / 16384.0;
    data.ay = rawY / 16384.0;
    data.az = rawZ / 16384.0;
    data.tilt = (abs(data.ax) > tiltThreshold || abs(data.ay) > tiltThreshold);
  }

  return data;
}
