/*
 * SoilSense.h
 */
#ifndef _SOIL_SENSE_H
#define _SOIL_SENSE_H
#include <Arduino.h>

class SoilSense {
public:
  SoilSense(uint8_t pin);
  init(int min, int max, byte samples = 10, byte lowpass = 20);
  int measure(byte samples = 10);
  byte value();

private:
  long convert(int value);
  uint8_t _pin;
  byte _lowpass;
  byte _samples;
  byte _value;
  long _min;
  long _max;
};

#endif
