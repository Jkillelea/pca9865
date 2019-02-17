#include "pca9865.h"

PCA9865 pca(0x5D);

void setup() {
    Serial.begin(9600);
    while (!Serial);
    delay(500);

    pca.begin();
}

void loop() {
    // All action handled by interrupt
}

void serialEvent() {
    if (Serial.available()) {
        uint8_t value = (uint8_t) Serial.parseInt();
        for (uint8_t chan = 0; chan < 16; chan++)
            pca.analogWrite(chan, value);

        while (Serial.available())   // a new line can get interpreted as a zero
            char _c = Serial.read(); // so we need to read in the rest of the buffer
    }                                // to prevent another call to serialEvent
}
