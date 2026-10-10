#include "ultrasonic.h"
#include "mq2.h"
#include "flame.h"
#include "mpu6050.h"

UltrasonicSensors ultrasonic(5, 18, 19, 23, 17, 16);
MQ2Sensor mq2(34, 1200);
FlameSensor flame(32);
MPUSensor imu(0x68, 0.5);

void setup() {
  Serial.begin(115200);
  ultrasonic.begin();
  mq2.begin();
  flame.begin();
  imu.begin(21, 22);
  delay(500);
}

void loop() {
  UltrasonicReadings u = ultrasonic.readAll();
  MQ2Readings g = mq2.read();
  bool flameDetected = flame.isFlameDetected();
  MPUReadings m = imu.read();

  Serial.print("{\"source\":\"esp32\"");
  Serial.print(",\"front_cm\":");
  Serial.print(u.front, 1);
  Serial.print(",\"left_cm\":");
  Serial.print(u.left, 1);
  Serial.print(",\"right_cm\":");
  Serial.print(u.right, 1);
  Serial.print(",\"gas_raw\":");
  Serial.print(g.raw);
  Serial.print(",\"gas_volt\":");
  Serial.print(g.voltage, 2);
  Serial.print(",\"gas_alert\":");
  Serial.print(g.alert ? "true" : "false");
  Serial.print(",\"flame_detected\":");
  Serial.print(flameDetected ? "true" : "false");
  Serial.print(",\"acc_x\":");
  Serial.print(m.ax, 2);
  Serial.print(",\"acc_y\":");
  Serial.print(m.ay, 2);
  Serial.print(",\"acc_z\":");
  Serial.print(m.az, 2);
  Serial.print(",\"tilt\":");
  Serial.print(m.tilt ? "true" : "false");
  Serial.println("}");

  delay(150);
}
