/*
 * SoilSense.h
 */
#ifndef _RAIN_SENSE_H
#define _RAIN_SENSE_H
#include <Arduino.h>

class SoilSense {
public:
  SoilSense(uint8_t pin);
  int measure();
  byte value(int min, int max);

private:
  long convert(int value);
  uint8_t _pin;
  long _min;
  long _max;
};

#endif
