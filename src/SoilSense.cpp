/*
 * SoilSense.cpp
 */
#include <Arduino.h>
#include "SoilSense.h"

SoilSense::SoilSense(uint8_t pin) {
  _pin = pin;
  pinMode(pin, INPUT);
}

long SoilSense::measure() {
  long val = 0;
  for (size_t i = 0; i < 10; i++) {
    val += analogRead(_pin);
  }
  val = 0x100000 / (val / 10 + 1);
  return val;
}

byte SoilSense::value(long min, long max) {
  _min = min;
  _max = max;
  long rawVal = measure();
  rawVal -= _min;
  if(rawVal < 0) rawVal = 0;
  rawVal = rawVal * 100 / (_max - _min);
  byte val = 100;
  if(rawVal < 100) val = (byte)rawVal;
  return val;
}
