#include "WaveCraft.h"

WaveCraft::WaveCraft(float frequency, float amplitude, float phase) {
  _frequencyHz = frequency;
  _amplitude = amplitude;
  _low = -amplitude / 2;
  _high = amplitude / 2;
  _phase = phase;
  _startTime = millis();
}

void WaveCraft::setAmplitude(float amplitude) {
  _amplitude = amplitude;
}

void WaveCraft::setFrequency(float frequency) {
  _frequencyHz = frequency;
}

void WaveCraft::setPhase(float phase) {
  _phase = phase;
}

void WaveCraft::setLow(float low) {
  _low = low;
}

void WaveCraft::setHigh(float high) {
  _high = high;
}

float WaveCraft::getLow() {
  return _low;
}

float WaveCraft::getHigh() {
  return _high;
}

float WaveCraft::getValue() {
  unsigned long currentTime = millis();
  float timeSeconds = (currentTime - _startTime) / 1000.0;
  float value = _amplitude * isin(degrees(2 * PI * _frequencyHz * timeSeconds + _phase));
  return mapFloat(value, -_amplitude, _amplitude, _low, _high);
}

int WaveCraft::getIntValue() {
  unsigned long currentTime = millis();
  float timeSeconds = (currentTime - _startTime) / 1000.0;
  float value = _amplitude * isin(degrees(2 * PI * _frequencyHz * timeSeconds + _phase));
  return (int)mapFloat(value, -_amplitude, _amplitude, _low, _high);
}