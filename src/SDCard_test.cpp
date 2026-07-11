#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

const int sd = 5;

void setup() {
    Serial.begin(115200);

    if (!SD.begin(sd)) {
        Serial.println("ts didnt initialize SD card");
        return;
    }
    File file = SD.open("/test.txt", FILE_WRITE);
    if (file) {
        file.print("Hello!");
        file.close();
        Serial.println("done");
    }
    else {
        Serial.println("error");
    }
}

void loop() {

}


