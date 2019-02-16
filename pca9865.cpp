// PCA9865
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
    Wire.begin();
}

// Initialize config registers
void PCA9865::begin() {
    // disable basically everything
    disableRestart(false);
    disableExtclk(false);
    disableSleep(false);
    disableAi(false);
    disableSleep(false);
    disableSub1(false);
    disableSub2(false);
    disableSub3(false);
    disableAllCall(false);

    disableInvert(false);
    disableTotemPole(false);

    writeConfig();
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
    uint16_t on_time = 1; // counter time before input is turned on
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
    writeRegister(channel_on_h,  (on_time >> 8)  & 0xFF);
    writeRegister(channel_on_l,   on_time        & 0xFF);
    writeRegister(channel_off_h, (off_time >> 8) & 0xFF);
    writeRegister(channel_off_l,  off_time       & 0xFF);
}

// write a byte to a register
void PCA9865::writeRegister(uint8_t reg, uint8_t data) {
    char buf[9] = {0};

    Serial.print("Sending ");
    sprint_bin(data, buf);
    Serial.print(buf);
    Serial.print(" to 0x");
    Serial.println(reg, HEX);

    Wire.beginTransmission(addr);
    Wire.write(reg);
    Wire.write(data);
    Wire.endTransmission();
}

uint8_t PCA9865::readRegister(uint8_t reg) {
    char buf[9] = {0};

    Wire.requestFrom(addr, (uint8_t) 1); // ISO C++ warns if an integer literal
    while (!Wire.available());           // is converted implicitly to a uint8_t
    uint8_t result = Wire.read();

    Serial.print("Read ");
    sprint_bin(result, buf);
    Serial.print(buf);
    Serial.print(" from  0x");
    Serial.println(reg, HEX);

    return result;
}
