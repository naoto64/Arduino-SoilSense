/*
 * SoilSense.h
 */
#ifndef _SOIL_SENSE_H
#define _SOIL_SENSE_H
#include <Arduino.h>

class SoilSense {
public:
  SoilSense(uint8_t pin);
  init(int min, int max, byte lowpass);
  int measure();
  byte value();

private:
  long convert(int value);
  uint8_t _pin;
  byte _lowpass;
  int _value;
  long _min;
  long _max;
};

#endif
