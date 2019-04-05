// PCA9865 - a library for the PCA9865 PWM expander and LED driver chip
// Example application

/*
 * Copyright 2019 Jacob Killelea <jkillelea@protonmail.ch>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of 
 * this software and associated documentation files (the "Software"), to deal in the 
 * Software without restriction, including without limitation the rights to use, copy, 
 * modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, 
 * and to permit persons to whom the Software is furnished to do so, subject to the 
 * following conditions:
 * The above copyright notice and this permission notice shall be included in all 
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF 
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "pca9865.h"

const uint8_t OE   = A3; // Active low
const uint8_t ADDR = 0x5D;
const uint8_t CHAN = 11;

PCA9865 pca(ADDR);

void setup() {
    Serial.begin(9600);
    pinMode(OE, OUTPUT);
    digitalWrite(OE, LOW);
    delay(500);

    pca.begin();
    while (!Serial);
}

void loop() {
    // All action handled by interrupt
}

void serialEvent() {
    if (Serial.available()) {
        uint8_t value = (uint8_t) Serial.parseInt();
        pca.analogWrite(CHAN, value);

        while (Serial.available())   // a new line can get interpreted as a zero
            Serial.read();           // so we need to read in the rest of the buffer
    }                                // to prevent another call to serialEvent
}

