Arduino-SoilSense
====

## Overview

This is a soil moisture sensor library for Arduino. Connect the pins to the analog pin (requires pull-down resistor) and the 5V pin. If you use this library, the soil moisture will be returned in the range of 0-100. You can also make your own sensor terminals using metal bars or aluminum tape.

## Demo

````cpp:example.ino
#include <SoilSense.h>
SoilSense ss = SoilSense(A0);

void setup () {
  Serial.begin(9600);
  ss.init(550, 800);
}

void loop () {
  byte val = ss.value();
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
SoilSense init(byte min, byte max, byte samples = 1, byte lowpass = 20)
````

    min: Value when the soil is dry. Get with measure().   
    max: The maximum amount of soil that can contain water. Get with measure().    
    samples: The number of samplings.    
    lowpass: The value of the low pass filter. The larger the value, the smoother it becomes.    

    Initialize SoilSense.

````cpp:example.ino
measure(byte samples = 1)
````

    samples: The number of samplings.    

    The raw value of the sensor. The range of values is 0 to 1023.

````cpp:example.ino
value()
````

    Returns the soil moisture in bytes. The range of values is 0 to 100.

## License

MIT
