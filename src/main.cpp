#include <Arduino.h>
#include <Wire.h>
#include "t2d.h"

T2D tempSens;

void setup() {
    Serial.begin(9600);
    Wire.begin();

    tempSens.INIT(0b01100000);
}

void loop() {
    Serial.println(tempSens.getTemp(), 4);
    delay(250);
}