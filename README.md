Arduino-SoilSense
====

## Overview

This is a soil moisture sensor library for Arduino. Connect the pins to the analog pin (requires pull-down resistor) and the 5V pin. If you use this library, the soil moisture will be returned in the range of 0-100. You can also make your own sensor terminals using metal bars or aluminum tape.

[![Soil moisture sensor](https://img.youtube.com/vi/bV2YAm3c4bY/0.jpg)](https://www.youtube.com/watch?v=bV2YAm3c4bY)

## Demo

````cpp:example.ino
/*
 * LED ------ 11 Pin
 * Speaker -- 12 Pin
 * Sensor --- A0 Pin
 */

#include <SoilSense.h>

SoilSense ss = SoilSense(A0);
int time = 0;

void setup () {
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  ss.init(650, 800, 10, 95);
}

void loop () {
  byte val = ss.value();
  if(time >= 1000 / (val + 1)){
    time = 0;
    tone(12, 440, 50);
    digitalWrite(11, HIGH);
  }else{
    time++;
    digitalWrite(11, LOW);
  }
  delay(10);
  Serial.println(val);
}
````

## Usage

#### Method


````cpp:example.ino
SoilSense SoilSense(uint8_t pin)
````

    pin: Analog pin number  

    Create an instance.

````cpp:example.ino
SoilSense.init(int min, int max, byte samples = 10, byte lowpass = 20)
````

    min: Value when the soil is dry. Get with measure().   
    max: The maximum amount of soil that can contain water. Get with measure().    
    samples: The number of samplings.    
    lowpass: The value of the low pass filter. The larger the value, the smoother it becomes.    

    Initialize SoilSense.

````cpp:example.ino
SoilSense.measure(byte samples = 10)
````

    samples: The number of samplings.    

    The raw value of the sensor. The range of values is 0 to 1023.

````cpp:example.ino
SoilSense.value()
````

    Returns the soil moisture in bytes. The range of values is 0 to 100.

## License

MIT
