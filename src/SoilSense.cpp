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
  int val = 0;
  for (size_t i = 0; i < 10; i++) {
    val += analogRead(_pin);
  }
  return val;
}

byte SoilSense::value(int min, int max) {
  _min = convert(min);
  _max = convert(max);
  long rawVal = convert(measure());
  rawVal -= _min;
  if(rawVal < 0) rawVal = 0;
  rawVal = rawVal * 100 / (_max - _min);
  byte val = 100;
  if(rawVal < 100) val = (byte)rawVal;
  return val;
}

long SoilSense::convert(int value) {
  return 0x100000 - 0x100000 / ((long)value + 1);
}
