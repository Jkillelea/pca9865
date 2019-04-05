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

#include <stdio.h>
#include <stdbool.h>
#include <wiringPi.h>
#include "pca9865.h"

const uint8_t OE   = 26; // GPIO 12, header pin 32, active low
const uint8_t ADDR = 0x55;

bool is_between(int val, int lo, int hi) {
    return (lo <= val) && (val <= hi);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s [channel 0-3] [duty cycle 0-100]\n", argv[0]);
        return -1;
    }

    int channel    = atoi(argv[1]);
    int duty_cycle = atoi(argv[2]);

    if (is_between(channel, 0, 3) && is_between(duty_cycle, 0, 100)) {
        PCA9865 pca(ADDR);
        wiringPiSetup();
        pinMode(OE, OUTPUT);
        digitalWrite(OE, LOW);
        pca.begin();
        pca.analogWrite(channel, duty_cycle);
    } else {
        fprintf(stderr, "channel must be between 0-3 and duty cycle must be between 0-100\n");
        return -2;
    }

    return 0;
}


