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
  uint8_t _pin;
  int _min;
  int _max;
};

#endif
