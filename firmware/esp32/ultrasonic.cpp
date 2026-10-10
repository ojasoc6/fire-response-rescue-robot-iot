#include "ultrasonic.h" 

UltrasonicSensors::UltrasonicSensors(int tf, int ef, int tl, int el, int tr, int er)
  : trigFront(tf), echoFront(ef),
    trigLeft(tl), echoLeft(el),
    trigRight(tr), echoRight(er) {}

void UltrasonicSensors::begin() {
  pinMode(trigFront, OUTPUT);
  pinMode(echoFront, INPUT);

  pinMode(trigLeft, OUTPUT);
  pinMode(echoLeft, INPUT);

  if (trigRight >= 0 && echoRight >= 0) {
    pinMode(trigRight, OUTPUT);
    pinMode(echoRight, INPUT);
  }
}

float UltrasonicSensors::measureSingle(int trigPin, int echoPin) {
  if (trigPin < 0 || echoPin < 0) return -1.0;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) return -1.0;
  return (duration * 0.0343) / 2.0;
}

UltrasonicReadings UltrasonicSensors::readAll() {
  UltrasonicReadings data;
  data.front = measureSingle(trigFront, echoFront);
  delay(10);
  data.left = measureSingle(trigLeft, echoLeft);
  delay(10);
  data.right = measureSingle(trigRight, echoRight);
  return data;
}
