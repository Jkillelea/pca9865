// PCA9865 - a library for the PCA9865 PWM expander and LED driver chip
// Main source file

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
 * copies or substantial portions of the Software
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <pca9865.h>
#include <pca9865_constants.h>

namespace {
    // print a binary number as fixed width
    void sprint_bin(uint8_t num, char *dest) {
        for (uint8_t i = 0; i < 8; i++) { // each bit
            if ( ((num >> i) & 1) == 1 ) // bit is a 1
                dest[7-i] = '1';
            else
                dest[7-i] = '0';
        }
    }

}


PCA9865::PCA9865(uint8_t address) {
    addr = address;
}

// Initialize config registers
void PCA9865::begin() {
    i2c_bus_init();

    reg_mode1 = readRegister(reg_addr::MODE1);
    reg_mode2 = readRegister(reg_addr::MODE2);

    // disable basically everything
    disableRestart(false);
    disableExtclk(false);
    disableSleep(false);
    disableAi(false);
    disableSub1(false);
    disableSub2(false);
    disableSub3(false);
    disableAllCall(false);

    disableInvert(false);
    enableTotemPole(false);

    // reg_mode2 = 0b00001100;
    writeConfig();

#ifdef ARDUINO
    // zero out all the channels on start
    // this behavior works on arduino because begin() will be called once during setup()
    // but on Linux it doesn't make sense because I'm compiling this down to command line
    // utilities that I call repeatedly
    for (uint8_t chan = 0; chan < 16; chan++)
        analogWrite(chan, 0);
#endif // ARDUINO
}

// write configuration to the actual chip
inline void PCA9865::writeConfig() {
    writeRegister(reg_addr::MODE1, reg_mode1);
    writeRegister(reg_addr::MODE2, reg_mode2);
}

void PCA9865::enableRestart(bool immediate) {
    reg_mode1 |= mode1::RESTART;
    if (immediate)
        writeConfig();
}

void PCA9865::disableRestart(bool immediate) {
    reg_mode1 &= ~mode1::RESTART;
    if (immediate)
        writeConfig();
}

void PCA9865::enableExtclk(bool immediate) {
    reg_mode1 |= mode1::EXTCLK;
    if (immediate)
        writeConfig();
}

void PCA9865::disableExtclk(bool immediate) {
    reg_mode1 &= ~mode1::EXTCLK;
    if (immediate)
        writeConfig();
}

void PCA9865::enableAi(bool immediate) {
    reg_mode1 |= mode1::AI;
    if (immediate)
        writeConfig();
}

void PCA9865::disableAi(bool immediate) {
    reg_mode1 &= ~mode1::AI;
    if (immediate)
        writeConfig();
}

void PCA9865::enableSleep(bool immediate) {
    reg_mode1 |= mode1::SLEEP;
    if (immediate)
        writeConfig();
}

void PCA9865::disableSleep(bool immediate) {
    reg_mode1 &= ~mode1::SLEEP;
    if (immediate)
        writeConfig();
}

void PCA9865::enableSub1(bool immediate) {
    reg_mode1 |= mode1::SUB1;
    if (immediate)
        writeConfig();
}

void PCA9865::disableSub1(bool immediate) {
    reg_mode1 &= ~mode1::SUB1;
    if (immediate)
        writeConfig();
}

void PCA9865::enableSub2(bool immediate) {
    reg_mode1 |= mode1::SUB2;
    if (immediate)
        writeConfig();
}

void PCA9865::disableSub2(bool immediate) {
    reg_mode1 &= ~mode1::SUB2;
    if (immediate)
        writeConfig();
}

void PCA9865::enableSub3(bool immediate) {
    reg_mode1 |= mode1::SUB3;
    if (immediate)
        writeConfig();
}

void PCA9865::disableSub3(bool immediate) {
    reg_mode1 &= ~mode1::SUB3;
    if (immediate)
        writeConfig();
}

void PCA9865::enableAllCall(bool immediate) {
    reg_mode1 |= mode1::ALLCALL;
    if (immediate)
        writeConfig();
}

void PCA9865::disableAllCall(bool immediate) {
    reg_mode1 &= ~mode1::ALLCALL;
    if (immediate)
        writeConfig();
}

void PCA9865::enableInvert(bool immediate) {
    reg_mode2 |= mode2::INVRT;
    if (immediate)
        writeConfig();
}

void PCA9865::disableInvert(bool immediate) {
    reg_mode2 &= ~mode2::INVRT;
    if (immediate)
        writeConfig();
}

void PCA9865::enableTotemPole(bool immediate) {
    reg_mode2 |= mode2::OUTDRV;
    if (immediate)
        writeConfig();
}

void PCA9865::disableTotemPole(bool immediate) {
    reg_mode2 &= ~mode2::OUTDRV;
    if (immediate)
        writeConfig();
}

bool PCA9865::isRestart(bool fetch) {
    if (fetch)
        reg_mode1 = readRegister(reg_addr::MODE1);
    return (reg_mode1 & mode1::RESTART) > 0;
}

bool PCA9865::isExtclk(bool fetch) {
    if (fetch)
        reg_mode1 = readRegister(reg_addr::MODE1);
    return (reg_mode1 & mode1::EXTCLK) > 0;
}

bool PCA9865::isAi(bool fetch) {
    if (fetch)
        reg_mode1 = readRegister(reg_addr::MODE1);
    return (reg_mode1 & mode1::AI) > 0;
}

bool PCA9865::isSleep(bool fetch) {
    if (fetch)
        reg_mode1 = readRegister(reg_addr::MODE1);
    return (reg_mode1 & mode1::SLEEP) > 0;
}

bool PCA9865::isSub1(bool fetch) {
    if (fetch)
        reg_mode1 = readRegister(reg_addr::MODE1);
    return (reg_mode1 & mode1::SUB1) > 0;
}

bool PCA9865::isSub2(bool fetch) {
    if (fetch)
        reg_mode1 = readRegister(reg_addr::MODE1);
    return (reg_mode1 & mode1::SUB2) > 0;
}

bool PCA9865::isSub3(bool fetch) {
    if (fetch)
        reg_mode1 = readRegister(reg_addr::MODE1);
    return (reg_mode1 & mode1::SUB3) > 0;
}

bool PCA9865::isAllCall(bool fetch) {
    if (fetch)
        reg_mode1 = readRegister(reg_addr::MODE1);
    return (reg_mode1 & mode1::ALLCALL) > 0;
}

bool PCA9865::isInvert(bool fetch) {
    if (fetch)
        reg_mode2 = readRegister(reg_addr::MODE2);
    return (reg_mode1 & mode2::INVRT) > 0;
}

bool PCA9865::isTotemPole(bool fetch) {
    if (fetch)
        reg_mode2 = readRegister(reg_addr::MODE2);
    return (reg_mode1 & mode2::OUTDRV) > 0;
}

void PCA9865::analogWrite(uint8_t chan, uint8_t percent) {
    uint16_t on_time  = 1; // counter time before input is turned on
    uint16_t off_time = (((float) percent*4094)/100.0) + 1;

    uint8_t channel_on_l;
    uint8_t channel_on_h;
    uint8_t channel_off_l;
    uint8_t channel_off_h;

    switch (chan) { // match channel to apropriate registers
        case 0:
            channel_on_l  = reg_addr::LED0_ON_L;
            channel_on_h  = reg_addr::LED0_ON_H;
            channel_off_l = reg_addr::LED0_OFF_L;
            channel_off_h = reg_addr::LED0_OFF_H;
            break;
        case 1:
            channel_on_l  = reg_addr::LED1_ON_L;
            channel_on_h  = reg_addr::LED1_ON_H;
            channel_off_l = reg_addr::LED1_OFF_L;
            channel_off_h = reg_addr::LED1_OFF_H;
            break;
        case 2:
            channel_on_l  = reg_addr::LED2_ON_L;
            channel_on_h  = reg_addr::LED2_ON_H;
            channel_off_l = reg_addr::LED2_OFF_L;
            channel_off_h = reg_addr::LED2_OFF_H;
            break;
        case 3:
            channel_on_l  = reg_addr::LED3_ON_L;
            channel_on_h  = reg_addr::LED3_ON_H;
            channel_off_l = reg_addr::LED3_OFF_L;
            channel_off_h = reg_addr::LED3_OFF_H;
            break;
        case 4:
            channel_on_l  = reg_addr::LED4_ON_L;
            channel_on_h  = reg_addr::LED4_ON_H;
            channel_off_l = reg_addr::LED4_OFF_L;
            channel_off_h = reg_addr::LED4_OFF_H;
            break;
        case 5:
            channel_on_l  = reg_addr::LED5_ON_L;
            channel_on_h  = reg_addr::LED5_ON_H;
            channel_off_l = reg_addr::LED5_OFF_L;
            channel_off_h = reg_addr::LED5_OFF_H;
            break;
        case 6:
            channel_on_l  = reg_addr::LED6_ON_L;
            channel_on_h  = reg_addr::LED6_ON_H;
            channel_off_l = reg_addr::LED6_OFF_L;
            channel_off_h = reg_addr::LED6_OFF_H;
            break;
        case 7:
            channel_on_l  = reg_addr::LED7_ON_L;
            channel_on_h  = reg_addr::LED7_ON_H;
            channel_off_l = reg_addr::LED7_OFF_L;
            channel_off_h = reg_addr::LED7_OFF_H;
            break;
        case 8:
            channel_on_l  = reg_addr::LED8_ON_L;
            channel_on_h  = reg_addr::LED8_ON_H;
            channel_off_l = reg_addr::LED8_OFF_L;
            channel_off_h = reg_addr::LED8_OFF_H;
            break;
        case 9:
            channel_on_l  = reg_addr::LED9_ON_L;
            channel_on_h  = reg_addr::LED9_ON_H;
            channel_off_l = reg_addr::LED9_OFF_L;
            channel_off_h = reg_addr::LED9_OFF_H;
            break;
        case 10:
            channel_on_l  = reg_addr::LED10_ON_L;
            channel_on_h  = reg_addr::LED10_ON_H;
            channel_off_l = reg_addr::LED10_OFF_L;
            channel_off_h = reg_addr::LED10_OFF_H;
            break;
        case 11:
            channel_on_l  = reg_addr::LED11_ON_L;
            channel_on_h  = reg_addr::LED11_ON_H;
            channel_off_l = reg_addr::LED11_OFF_L;
            channel_off_h = reg_addr::LED11_OFF_H;
            break;
        case 12:
            channel_on_l  = reg_addr::LED12_ON_L;
            channel_on_h  = reg_addr::LED12_ON_H;
            channel_off_l = reg_addr::LED12_OFF_L;
            channel_off_h = reg_addr::LED12_OFF_H;
            break;
        case 13:
            channel_on_l  = reg_addr::LED13_ON_L;
            channel_on_h  = reg_addr::LED13_ON_H;
            channel_off_l = reg_addr::LED13_OFF_L;
            channel_off_h = reg_addr::LED13_OFF_H;
            break;
        case 14:
            channel_on_l  = reg_addr::LED14_ON_L;
            channel_on_h  = reg_addr::LED14_ON_H;
            channel_off_l = reg_addr::LED14_OFF_L;
            channel_off_h = reg_addr::LED14_OFF_H;
            break;
        case 15:
            channel_on_l  = reg_addr::LED15_ON_L;
            channel_on_h  = reg_addr::LED15_ON_H;
            channel_off_l = reg_addr::LED15_OFF_L;
            channel_off_h = reg_addr::LED15_OFF_H;
            break;
        default:
            channel_on_l  = reg_addr::LED0_ON_L;
            channel_on_h  = reg_addr::LED0_ON_H;
            channel_off_l = reg_addr::LED0_OFF_L;
            channel_off_h = reg_addr::LED0_OFF_H;
            break;
    }

    // TODO: this works but might make more sense to have auto increment
    // TODO: only bottom 4 bits of the high byte register control duty cylce
    //       so ANDing with 0x0F instead of 0xFF, but need to verify this is
    //       correct. The top 4 bits are apparently some kind of control

    // writeRegister(channel_on_h,  (on_time >> 8)  & 0xFF);
    writeRegister(channel_on_h,  (on_time >> 8)  & 0x0F);
    writeRegister(channel_on_l,   on_time        & 0xFF);

    // writeRegister(channel_off_h, (off_time >> 8) & 0xFF);
    writeRegister(channel_off_h, (off_time >> 8) & 0x0F);
    writeRegister(channel_off_l,  off_time       & 0xFF);
}

void PCA9865::i2c_bus_init() {
#ifdef ARDUINO
    Wire.begin();
#else // Raspberry Pi
    i2c = std::unique_ptr<I2CDevice>(new I2CDevice(addr, "/dev/i2c-1"));
#endif
    }
// write a byte to a register
void PCA9865::writeRegister(uint8_t reg, uint8_t data) {
#ifdef ARDUINO
    Wire.beginTransmission(addr);
    Wire.write(reg);
    Wire.write(data);
    Wire.endTransmission();
#else // Raspberry Pi
    uint8_t buf[] = {reg, data};
    i2c->write(buf, 2);
#endif
}

uint8_t PCA9865::readRegister(uint8_t reg) {
#ifdef ARDUINO
    Wire.requestFrom(addr, (uint8_t) 1); // ISO C++ warns if an integer literal
    while (!Wire.available());           // is converted implicitly to a uint8_t
    uint8_t result = Wire.read();
#else // Raspberry Pi
    uint8_t result = reg; // TODO: check this
    i2c->write(&result, 1);
    i2c->read(&result, 1);
#endif

    return result;
}
