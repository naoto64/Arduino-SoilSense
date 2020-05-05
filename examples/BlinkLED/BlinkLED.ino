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
