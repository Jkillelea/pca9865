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

#include <wiringPi.h>
#include "pca9865.h"

const uint8_t OE   = 26; // GPIO 12, header pin 32, active low
const uint8_t ADDR = 0x55;
const uint8_t CHAN = 0;

PCA9865 pca(ADDR);

int main(int argc, char *argv[]) {
    wiringPiSetup();
    pinMode(OE, OUTPUT);
    digitalWrite(OE, LOW);

    pca.begin();

    while (true) {
        for (int i = 0; i <= 100; i++) {
            pca.analogWrite(CHAN, i);
            delay(50);
        }
        for (int i = 100; i > 0; i--) {
            pca.analogWrite(CHAN, i);
            delay(50);
        }
    }
}


