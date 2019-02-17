// PCA9865 - a library for the PCA9865 PWM expander and LED driver chip. 
// Constants file

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

namespace mode1 {
    const uint8_t RESTART = 1 << 7; // Restart the chip
    const uint8_t EXTCLK  = 1 << 6; // use an external clock. NOTE: should always be zero for us
    const uint8_t AI      = 1 << 5; // Auto increment reg addr after writing the last register
    const uint8_t SLEEP   = 1 << 4; // Low power mode
    const uint8_t SUB1    = 1 << 3; // respond to sub addr 1
    const uint8_t SUB2    = 1 << 2; // respond to sub addr 2
    const uint8_t SUB3    = 1 << 1; // respond to sub addr 3
    const uint8_t ALLCALL = 1 << 0; // respond to all call addr
} // end namespace mode1

namespace mode2 {
    const uint8_t INVRT  = 1 << 4; // invert output logic
    const uint8_t OCH    = 1 << 3; // output change on I2C STOP vs slave ACK
    const uint8_t OUTDRV = 1 << 2; // totem pole vs open drain

    /* related to the ~OE pin, but exact functionality is unclear */
    const uint8_t OUTNEh = 1 << 1;
    const uint8_t OUTNEl = 1 << 0;
} // end namespace mode2

// Register addresses
namespace reg_addr {
    const uint8_t MODE1         = 0x00; // r/w Mode register 1
    const uint8_t MODE2         = 0x01; // r/w Mode register 2
    const uint8_t SUBADR1       = 0x02; // r/w I2C bus subaddress 1
    const uint8_t SUBADR2       = 0x03; // r/w I2C bus subaddress 2
    const uint8_t SUBADR3       = 0x04; // r/w I2C bus subaddress 3
    const uint8_t ALLCALLADR    = 0x05; // r/w LED All Call I2C bus address
    const uint8_t LED0_ON_L     = 0x06; // r/w LED0 output and brightness control byte 0
    const uint8_t LED0_ON_H     = 0x07; // r/w LED0 output and brightness control byte 1
    const uint8_t LED0_OFF_L    = 0x08; // r/w LED0 output and brightness control byte 2
    const uint8_t LED0_OFF_H    = 0x09; // r/w LED0 output and brightness control byte 3
    const uint8_t LED1_ON_L     = 0x0A; // r/w LED1 output and brightness control byte 0
    const uint8_t LED1_ON_H     = 0x0B; // r/w LED1 output and brightness control byte 1
    const uint8_t LED1_OFF_L    = 0x0C; // r/w LED1 output and brightness control byte 2
    const uint8_t LED1_OFF_H    = 0x0D; // r/w LED1 output and brightness control byte 3
    const uint8_t LED2_ON_L     = 0x0E; // r/w LED2 output and brightness control byte 0
    const uint8_t LED2_ON_H     = 0x0F; // r/w LED2 output and brightness control byte 1
    const uint8_t LED2_OFF_L    = 0x10; // r/w LED2 output and brightness control byte 2
    const uint8_t LED2_OFF_H    = 0x11; // r/w LED2 output and brightness control byte 3
    const uint8_t LED3_ON_L     = 0x12; // r/w LED3 output and brightness control byte 0
    const uint8_t LED3_ON_H     = 0x13; // r/w LED3 output and brightness control byte 1
    const uint8_t LED3_OFF_L    = 0x14; // r/w LED3 output and brightness control byte 2
    const uint8_t LED3_OFF_H    = 0x15; // r/w LED3 output and brightness control byte 3
    const uint8_t LED4_ON_L     = 0x16; // r/w LED4 output and brightness control byte 0
    const uint8_t LED4_ON_H     = 0x17; // r/w LED4 output and brightness control byte 1
    const uint8_t LED4_OFF_L    = 0x18; // r/w LED4 output and brightness control byte 2
    const uint8_t LED4_OFF_H    = 0x19; // r/w LED4 output and brightness control byte 3
    const uint8_t LED5_ON_L     = 0x1A; // r/w LED5 output and brightness control byte 0
    const uint8_t LED5_ON_H     = 0x1B; // r/w LED5 output and brightness control byte 1
    const uint8_t LED5_OFF_L    = 0x1C; // r/w LED5 output and brightness control byte 2
    const uint8_t LED5_OFF_H    = 0x1D; // r/w LED5 output and brightness control byte 3
    const uint8_t LED6_ON_L     = 0x1E; // r/w LED6 output and brightness control byte 0
    const uint8_t LED6_ON_H     = 0x1F; // r/w LED6 output and brightness control byte 1
    const uint8_t LED6_OFF_L    = 0x20; // r/w LED6 output and brightness control byte 2
    const uint8_t LED6_OFF_H    = 0x21; // r/w LED6 output and brightness control byte 3
    const uint8_t LED7_ON_L     = 0x22; // r/w LED7 output and brightness control byte 0
    const uint8_t LED7_ON_H     = 0x23; // r/w LED7 output and brightness control byte 1
    const uint8_t LED7_OFF_L    = 0x24; // r/w LED7 output and brightness control byte 2
    const uint8_t LED7_OFF_H    = 0x25; // r/w LED7 output and brightness control byte 3
    const uint8_t LED8_ON_L     = 0x26; // r/w LED8 output and brightness control byte 0
    const uint8_t LED8_ON_H     = 0x27; // r/w LED8 output and brightness control byte 1
    const uint8_t LED8_OFF_L    = 0x28; // r/w LED8 output and brightness control byte 2
    const uint8_t LED8_OFF_H    = 0x29; // r/w LED8 output and brightness control byte 3
    const uint8_t LED9_ON_L     = 0x2A; // r/w LED9 output and brightness control byte 0
    const uint8_t LED9_ON_H     = 0x2B; // r/w LED9 output and brightness control byte 1
    const uint8_t LED9_OFF_L    = 0x2C; // r/w LED9 output and brightness control byte 2
    const uint8_t LED9_OFF_H    = 0x2D; // r/w LED9 output and brightness control byte 3
    const uint8_t LED10_ON_L    = 0x2E; // r/w LED10 output and brightness control byte 0
    const uint8_t LED10_ON_H    = 0x2F; // r/w LED10 output and brightness control byte 1
    const uint8_t LED10_OFF_L   = 0x30; // r/w LED10 output and brightness control byte 2
    const uint8_t LED10_OFF_H   = 0x31; // r/w LED10 output and brightness control byte 3
    const uint8_t LED11_ON_L    = 0x32; // r/w LED11 output and brightness control byte 0
    const uint8_t LED11_ON_H    = 0x33; // r/w LED11 output and brightness control byte 1
    const uint8_t LED11_OFF_L   = 0x34; // r/w LED11 output and brightness control byte 2
    const uint8_t LED11_OFF_H   = 0x35; // r/w LED11 output and brightness control byte 3
    const uint8_t LED12_ON_L    = 0x36; // r/w LED12 output and brightness control byte 0
    const uint8_t LED12_ON_H    = 0x37; // r/w LED12 output and brightness control byte 1
    const uint8_t LED12_OFF_L   = 0x38; // r/w LED12 output and brightness control byte 2
    const uint8_t LED12_OFF_H   = 0x39; // r/w LED12 output and brightness control byte 3
    const uint8_t LED13_ON_L    = 0x3A; // r/w LED13 output and brightness control byte 0
    const uint8_t LED13_ON_H    = 0x3B; // r/w LED13 output and brightness control byte 1
    const uint8_t LED13_OFF_L   = 0x3C; // r/w LED13 output and brightness control byte 2
    const uint8_t LED13_OFF_H   = 0x3D; // r/w LED13 output and brightness control byte 3
    const uint8_t LED14_ON_L    = 0x3E; // r/w LED14 output and brightness control byte 0
    const uint8_t LED14_ON_H    = 0x3F; // r/w LED14 output and brightness control byte 1
    const uint8_t LED14_OFF_L   = 0x40; // r/w LED14 output and brightness control byte 2
    const uint8_t LED14_OFF_H   = 0x41; // r/w LED14 output and brightness control byte 3
    const uint8_t LED15_ON_L    = 0x42; // r/w LED15 output and brightness control byte 0
    const uint8_t LED15_ON_H    = 0x43; // r/w LED15 output and brightness control byte 1
    const uint8_t LED15_OFF_L   = 0x44; // r/w LED15 output and brightness control byte 2
    const uint8_t LED15_OFF_H   = 0x45; // r/w LED15 output and brightness control byte 3
    const uint8_t ALL_LED_ON_L  = 0xFA; // w/r zero load all the LEDn_ON registers, byte 0
    const uint8_t ALL_LED_ON_H  = 0xFB; // w/r zero load all the LEDn_ON registers, byte 1
    const uint8_t ALL_LED_OFF_L = 0xFC; // w/r zero load all the LEDn_OFF registers, byte 0
    const uint8_t ALL_LED_OFF_H = 0xFD; // w/r zero load all the LEDn_OFF registers, byte 1
    const uint8_t PRE_SCALE     = 0xFE; // r/w prescaler for PWM output frequency
    const uint8_t TestMode      = 0xFF; // r/w defines the test mode to be entered
} // end namespace reg_addr

