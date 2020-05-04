/*
 * SoilSense.cpp
 */
#include <Arduino.h>
#include "SoilSense.h"

SoilSense::SoilSense(uint8_t pin) {
  _pin = pin;
  pinMode(pin, INPUT);
}

int SoilSense::measure() {
  int sum = 0;
  for (size_t i = 0; i < 10; i++) {
    sum += analogRead(_pin);
  }
  return sum / 10;
}

byte SoilSense::value(int min, int max) {
  _min = min;
  _max = max;
  int rawVal = measure();
  rawVal -= _min;
  if(rawVal < 0) rawVal = 0;
  byte val = (byte)(rawVal * 100 / (_max - _min));
  if(val > 100) val = 100;
  return val;
}
