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

    syncConfig();
}

// write configuration to the actual chip
inline void PCA9865::syncConfig() {
    writeRegister(reg_addr::MODE1, reg_mode1);
    writeRegister(reg_addr::MODE2, reg_mode2);
}

void PCA9865::setRestart(bool immediate) {
    reg_mode1 |= mode1::RESTART;
    if (immediate)
        syncConfig();
}

void PCA9865::disableRestart(bool immediate) {
    reg_mode1 &= ~mode1::RESTART;
    if (immediate)
        syncConfig();
}

void PCA9865::setExtclk(bool immediate) {
    reg_mode1 |= mode1::EXTCLK;
    if (immediate)
        syncConfig();
}

void PCA9865::disableExtclk(bool immediate) {
    reg_mode1 &= ~mode1::EXTCLK;
    if (immediate)
        syncConfig();
}

void PCA9865::setAi(bool immediate) {
    reg_mode1 |= mode1::AI;
    if (immediate)
        syncConfig();
}

void PCA9865::disableAi(bool immediate) {
    reg_mode1 &= ~mode1::AI;
    if (immediate)
        syncConfig();
}

void PCA9865::setSleep(bool immediate) {
    reg_mode1 |= mode1::SLEEP;
    if (immediate)
        syncConfig();
}

void PCA9865::disableSleep(bool immediate) {
    reg_mode1 &= ~mode1::SLEEP;
    if (immediate)
        syncConfig();
}

void PCA9865::setSub1(bool immediate) {
    reg_mode1 |= mode1::SUB1;
    if (immediate)
        syncConfig();
}

void PCA9865::disableSub1(bool immediate) {
    reg_mode1 &= ~mode1::SUB1;
    if (immediate)
        syncConfig();
}

void PCA9865::setSub2(bool immediate) {
    reg_mode1 |= mode1::SUB2;
    if (immediate)
        syncConfig();
}

void PCA9865::disableSub2(bool immediate) {
    reg_mode1 &= ~mode1::SUB2;
    if (immediate)
        syncConfig();
}

void PCA9865::setSub3(bool immediate) {
    reg_mode1 |= mode1::SUB3;
    if (immediate)
        syncConfig();
}

void PCA9865::disableSub3(bool immediate) {
    reg_mode1 &= ~mode1::SUB3;
    if (immediate)
        syncConfig();
}

void PCA9865::setAllCall(bool immediate) {
    reg_mode1 |= mode1::ALLCALL;
    if (immediate)
        syncConfig();
}

void PCA9865::disableAllCall(bool immediate) {
    reg_mode1 &= ~mode1::ALLCALL;
    if (immediate)
        syncConfig();
}

void PCA9865::setInvert(bool immediate) {
    reg_mode2 |= mode2::INVRT;
    if (immediate)
        syncConfig();
}

void PCA9865::disableInvert(bool immediate) {
    reg_mode2 &= ~mode2::INVRT;
    if (immediate)
        syncConfig();
}

void PCA9865::setTotemPole(bool immediate) {
    reg_mode2 |= mode2::OUTDRV;
    if (immediate)
        syncConfig();
}

void PCA9865::disableTotemPole(bool immediate) {
    reg_mode2 &= ~mode2::OUTDRV;
    if (immediate)
        syncConfig();
}

// write a byte to a register
void PCA9865::writeRegister(uint8_t reg, uint8_t data) {
    char buf[9] = {0};
    sprint_bin(data, buf);

    Serial.print("Sending ");
    Serial.print(buf);
    // Serial.print(data, BIN);
    Serial.print(" to 0x");
    Serial.println(reg, HEX);

    Wire.beginTransmission(addr);
    Wire.write(reg);
    Wire.write(data);
    Wire.endTransmission();
}
