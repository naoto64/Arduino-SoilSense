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
