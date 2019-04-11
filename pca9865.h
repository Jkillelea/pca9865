// PCA9865 - a library for the PCA9865 PWM expander and LED driver chip
// Header file

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

#pragma once

#include <stdint.h>

// Arduno Uno
#ifdef ARDUINO
#include <Arduino.h>
#include <Wire.h>
#endif

// Raspberry Pi
#ifdef __linux__
#include <i2cdevice.h>
#include <memory> // std::unique_ptr
#endif


class PCA9865 {
    public:
        PCA9865(uint8_t address);

        void begin();
        void writeConfig();
        void analogWrite(uint8_t channel, uint8_t val);

        // NOTE: default is to call syncConfig() right after changing
        // any parameter, but this can be deferred for the sake of efficiency
        // in case many things are changed at once
        void enableRestart( bool immediate = true);
        void disableRestart(bool immediate = true);
        // we want the external clock disabled
        void enableExtclk( bool immediate = true);
        void disableExtclk(bool immediate = true);
        // auto increment is a convience feature
        void enableAi( bool immediate = true);
        void disableAi(bool immediate = true);
        // enter sleep mode
        void enableSleep( bool immediate = true);
        void disableSleep(bool immediate = true);
        // whether to respond to sub addresses
        void enableSub1( bool immediate = true);
        void disableSub1(bool immediate = true);
        void enableSub2( bool immediate = true);
        void disableSub2(bool immediate = true);
        void enableSub3( bool immediate = true);
        void disableSub3(bool immediate = true);
        // whether to respond to all call address
        void enableAllCall( bool immediate = true);
        void disableAllCall(bool immediate = true);

        // Invert the PWM signals (NOTE 0% becomes FULL-BLAST with this)
        void enableInvert( bool immediate = true);
        void disableInvert(bool immediate = true);

        // Looks like totem pole driving is needed, but
        // figuring out exactly what the correct configuration is
        // is still TODO
        void enableTotemPole( bool immediate = true);
        void disableTotemPole(bool immediate = true);

        // check if each of the config bits is set
        // NOTE: default behavior is to fetch the actual
        // register off the chip each time. This does
        // present the risk of a bad I2C packet overwriting
        // the variable with garbage data.
        // If that happens we can just request the data again.
        bool isRestart(  bool fetch = true);
        bool isExtclk(   bool fetch = true);
        bool isAi(       bool fetch = true);
        bool isSleep(    bool fetch = true);
        bool isSub1(     bool fetch = true);
        bool isSub2(     bool fetch = true);
        bool isSub3(     bool fetch = true);
        bool isAllCall(  bool fetch = true);
        bool isInvert(   bool fetch = true);
        bool isTotemPole(bool fetch = true);

    private:
        void i2c_bus_init();
        void writeRegister(uint8_t reg, uint8_t data);
        uint8_t readRegister(uint8_t reg);

        uint8_t addr;      // I2C address
        uint8_t reg_mode1 = 0b00000000; // state of the MODE1 register
        uint8_t reg_mode2 = 0b00001011; // state of the MODE2 register

// Raspberry Pi
#ifdef __linux__
        std::unique_ptr<I2CDevice> i2c; // I2C backend
#endif
};
