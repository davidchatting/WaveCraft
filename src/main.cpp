#include <WaveCraft.h>

WaveCraft wave1(1, 100);

void setup() {
  Serial.begin(115200);

  wave1.setAmplitude(50);
  wave1.setFrequency(1);
  wave1.setPhase(0);
}

void loop() {
  float value1 = wave1.getValue();
  Serial.println(value1);
}