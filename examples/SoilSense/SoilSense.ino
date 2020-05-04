#include <SoilSense.h>
SoilSense ss = SoilSense(A0);

void setup () {
  Serial.begin(9600);
}

void loop () {
  byte val = ss.value(50, 500);
  Serial.println(val);
}
