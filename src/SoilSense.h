/*
 * SoilSense.h
 */
#ifndef _SOIL_SENSE_H
#define _SOIL_SENSE_H
#include <Arduino.h>

class SoilSense {
public:
  SoilSense(uint8_t pin);
  init(int min, int max, int samples=1, byte lowpass);
  int measure(int samples=1);
  byte value();

private:
  long convert(int value);
  uint8_t _pin;
  byte _lowpass
  int samples;
  int _value;
  long _min;
  long _max;
};

#endif
