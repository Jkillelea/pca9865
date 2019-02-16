#pragma once

#include <Arduino.h>
#include <Wire.h>

#include <stdint.h>

class PCA9865 {
    public:
        PCA9865(uint8_t address);

        void begin();
        void writeConfig();
        void analogWrite(uint8_t channel, uint8_t val);

        // NOTE: default is to call syncConfig() right after changing
        // any parameter, but this can be deferred for the sake of efficiency
        // in case many things are changed at once
        void setRestart(    bool immediate = true);
        void disableRestart(bool immediate = true);
        // we want the external clock disabled
        void setExtclk(    bool immediate = true); 
        void disableExtclk(bool immediate = true);
        // auto increment is a convience feature
        void setAi(    bool immediate = true);
        void disableAi(bool immediate = true);
        // enter sleep mode
        void setSleep(    bool immediate = true);
        void disableSleep(bool immediate = true);
        // whether to respond to sub addresses
        void setSub1(    bool immediate = true);
        void disableSub1(bool immediate = true);
        void setSub2(    bool immediate = true);
        void disableSub2(bool immediate = true);
        void setSub3(    bool immediate = true);
        void disableSub3(bool immediate = true);
        // whether to respond to all call address
        void setAllCall(    bool immediate = true);
        void disableAllCall(bool immediate = true);
        // Invert the PWM signals (NOTE 0% becomes FULL-BLAST with this)
        void setInvert(    bool immediate = true);
        void disableInvert(bool immediate = true);
        // We always want totem pole driving disabled. 
        // It's meant for LEDs, not  power mosfets
        void setTotemPole(    bool immediate = true);
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
        void writeRegister(uint8_t reg, uint8_t data);
        uint8_t readRegister(uint8_t reg);

        uint8_t addr;      // I2C address
        uint8_t reg_mode1; // state of the MODE1 register
        uint8_t reg_mode2; // state of the MODE2 register
};
