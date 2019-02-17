#include "pca9865.h"

const uint8_t ADDR = 0x5D;
const uint8_t CHAN = 11;

PCA9865 pca(ADDR);

void setup() {
    Serial.begin(9600);
    while (!Serial);
    delay(500);

    pca.begin();
}

void loop() {
    for (int i = 0; i <= 100; i++) {
        pca.analogWrite(CHAN, i);
        delay(50);
    }
    for (int i = 100; i > 0; i--) {
        pca.analogWrite(CHAN, i);
        delay(50);
    }
}

