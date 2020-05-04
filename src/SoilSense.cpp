/*
 * SoilSense.cpp
 */
#include <Arduino.h>
#include "SoilSense.h"

SoilSense::SoilSense(uint8_t pin) {
  _pin = pin;
  _value = 0;
  pinMode(pin, INPUT_PULLUP);
}

int SoilSense::init(int min, int max, byte samples, byte lowpass) {
  _min = convert(min);
  _max = convert(max);
  _samples = samples;
  _lowpass = lowpass;
}

int SoilSense::measure(byte samples) {
  int val = 1023 * (int)samples;
  for (size_t i = 0; i < samples; i++) {
    val -= analogRead(_pin);
  }
  return val / samples;
}

byte SoilSense::value() {
  long rawVal = convert(measure(_samples));
  rawVal -= _min;
  if(rawVal < 0) rawVal = 0;
  rawVal = rawVal * 100 / (_max - _min);
  if(rawVal > 100) rawVal = 100;
  _value = (byte)(rawVal * (100 - _lowpass) / 100 + (int)_value * _lowpass / 100);
  return _value;
}

long SoilSense::convert(int value) {
  return 0x100000 - 0x100000 / ((long)value + 1);
}
