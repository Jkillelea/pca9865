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
}

// Register addresses
namespace reg_addr {
    const uint8_t MODE1         = 0x00; // read/write Mode register 1
    const uint8_t MODE2         = 0x01; // read/write Mode register 2
    const uint8_t SUBADR1       = 0x02; // read/write I 2 C-bus subaddress 1
    const uint8_t SUBADR2       = 0x03; // read/write I 2 C-bus subaddress 2
    const uint8_t SUBADR3       = 0x04; // read/write I 2 C-bus subaddress 3
    const uint8_t ALLCALLADR    = 0x05; // read/write LED All Call I 2 C-bus address
    const uint8_t LED0_ON_L     = 0x06; // read/write LED0 output and brightness control byte 0
    const uint8_t LED0_ON_H     = 0x07; // read/write LED0 output and brightness control byte 1
    const uint8_t LED0_OFF_L    = 0x08; // read/write LED0 output and brightness control byte 2
    const uint8_t LED0_OFF_H    = 0x09; // read/write LED0 output and brightness control byte 3
    const uint8_t LED1_ON_L     = 0x0A; // read/write LED1 output and brightness control byte 0
    const uint8_t LED1_ON_H     = 0x0B; // read/write LED1 output and brightness control byte 1
    const uint8_t LED1_OFF_L    = 0x0C; // read/write LED1 output and brightness control byte 2
    const uint8_t LED1_OFF_H    = 0x0D; // read/write LED1 output and brightness control byte 3
    const uint8_t LED2_ON_L     = 0x0E; // read/write LED2 output and brightness control byte 0
    const uint8_t LED2_ON_H     = 0x0F; // read/write LED2 output and brightness control byte 1
    const uint8_t LED2_OFF_L    = 0x10; // read/write LED2 output and brightness control byte 2
    const uint8_t LED2_OFF_H    = 0x11; // read/write LED2 output and brightness control byte 3
    const uint8_t LED3_ON_L     = 0x12; // read/write LED3 output and brightness control byte 0
    const uint8_t LED3_ON_H     = 0x13; // read/write LED3 output and brightness control byte 1
    const uint8_t LED3_OFF_L    = 0x14; // read/write LED3 output and brightness control byte 2
    const uint8_t LED3_OFF_H    = 0x15; // read/write LED3 output and brightness control byte 3
    const uint8_t LED4_ON_L     = 0x16; // read/write LED4 output and brightness control byte 0
    const uint8_t LED4_ON_H     = 0x17; // read/write LED4 output and brightness control byte 1
    const uint8_t LED4_OFF_L    = 0x18; // read/write LED4 output and brightness control byte 2
    const uint8_t LED4_OFF_H    = 0x19; // read/write LED4 output and brightness control byte 3
    const uint8_t LED5_ON_L     = 0x1A; // read/write LED5 output and brightness control byte 0
    const uint8_t LED5_ON_H     = 0x1B; // read/write LED5 output and brightness control byte 1
    const uint8_t LED5_OFF_L    = 0x1C; // read/write LED5 output and brightness control byte 2
    const uint8_t LED5_OFF_H    = 0x1D; // read/write LED5 output and brightness control byte 3
    const uint8_t LED6_ON_L     = 0x1E; // read/write LED6 output and brightness control byte 0
    const uint8_t LED6_ON_H     = 0x1F; // read/write LED6 output and brightness control byte 1
    const uint8_t LED6_OFF_L    = 0x20; // read/write LED6 output and brightness control byte 2
    const uint8_t LED6_OFF_H    = 0x21; // read/write LED6 output and brightness control byte 3
    const uint8_t LED7_ON_L     = 0x22; // read/write LED7 output and brightness control byte 0
    const uint8_t LED7_ON_H     = 0x23; // read/write LED7 output and brightness control byte 1
    const uint8_t LED7_OFF_L    = 0x24; // read/write LED7 output and brightness control byte 2
    const uint8_t LED7_OFF_H    = 0x25; // read/write LED7 output and brightness control byte 3
    const uint8_t LED8_ON_L     = 0x26; // read/write LED8 output and brightness control byte 0
    const uint8_t LED8_ON_H     = 0x27; // read/write LED8 output and brightness control byte 1
    const uint8_t LED8_OFF_L    = 0x28; // read/write LED8 output and brightness control byte 2
    const uint8_t LED8_OFF_H    = 0x29; // read/write LED8 output and brightness control byte 3
    const uint8_t LED9_ON_L     = 0x2A; // read/write LED9 output and brightness control byte 0
    const uint8_t LED9_ON_H     = 0x2B; // read/write LED9 output and brightness control byte 1
    const uint8_t LED9_OFF_L    = 0x2C; // read/write LED9 output and brightness control byte 2
    const uint8_t LED9_OFF_H    = 0x2D; // read/write LED9 output and brightness control byte 3
    const uint8_t LED10_ON_L    = 0x2E; // read/write LED10 output and brightness control byte 0
    const uint8_t LED10_ON_H    = 0x2F; // read/write LED10 output and brightness control byte 1
    const uint8_t LED10_OFF_L   = 0x30; // read/write LED10 output and brightness control byte 2
    const uint8_t LED10_OFF_H   = 0x31; // read/write LED10 output and brightness control byte 3
    const uint8_t LED11_ON_L    = 0x32; // read/write LED11 output and brightness control byte 0
    const uint8_t LED11_ON_H    = 0x33; // read/write LED11 output and brightness control byte 1
    const uint8_t LED11_OFF_L   = 0x34; // read/write LED11 output and brightness control byte 2
    const uint8_t LED11_OFF_H   = 0x35; // read/write LED11 output and brightness control byte 3
    const uint8_t LED12_ON_L    = 0x36; // read/write LED12 output and brightness control byte 0
    const uint8_t LED12_ON_H    = 0x37; // read/write LED12 output and brightness control byte 1
    const uint8_t LED12_OFF_L   = 0x38; // read/write LED12 output and brightness control byte 2
    const uint8_t LED12_OFF_H   = 0x39; // read/write LED12 output and brightness control byte 3
    const uint8_t LED13_ON_L    = 0x3A; // read/write LED13 output and brightness control byte 0
    const uint8_t LED13_ON_H    = 0x3B; // read/write LED13 output and brightness control byte 1
    const uint8_t LED13_OFF_L   = 0x3C; // read/write LED13 output and brightness control byte 2
    const uint8_t LED13_OFF_H   = 0x3D; // read/write LED13 output and brightness control byte 3
    const uint8_t LED14_ON_L    = 0x3E; // read/write LED14 output and brightness control byte 0
    const uint8_t LED14_ON_H    = 0x3F; // read/write LED14 output and brightness control byte 1
    const uint8_t LED14_OFF_L   = 0x40; // read/write LED14 output and brightness control byte 2
    const uint8_t LED14_OFF_H   = 0x41; // read/write LED14 output and brightness control byte 3
    const uint8_t LED15_ON_L    = 0x42; // read/write LED15 output and brightness control byte 0
    const uint8_t LED15_ON_H    = 0x43; // read/write LED15 output and brightness control byte 1
    const uint8_t LED15_OFF_L   = 0x44; // read/write LED15 output and brightness control byte 2
    const uint8_t LED15_OFF_H   = 0x45; // read/write LED15 output and brightness control byte 3
    const uint8_t ALL_LED_ON_L  = 0xFA; // write/read zero load all the LEDn_ON registers, byte 0
    const uint8_t ALL_LED_ON_H  = 0xFB; // write/read zero load all the LEDn_ON registers, byte 1
    const uint8_t ALL_LED_OFF_L = 0xFC; // write/read zero load all the LEDn_OFF registers, byte 0
    const uint8_t ALL_LED_OFF_H = 0xFD; // write/read zero load all the LEDn_OFF registers, byte 1
    const uint8_t PRE_SCALE     = 0xFE; // read/write prescaler for PWM output frequency
    const uint8_t TestMode      = 0xFF; // read/write defines the test mode to be entered
} // end namespace reg_addr

