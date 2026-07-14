#include <Arduino.h>
#include <driver/i2s.h>
#include <SPI.h>
#include <SD.h>

const int sd_cs = 15;
const int sd_sck = 14;
const int sd_mosi = 13;
const int sd_miso = 4;
const int ws = 19;
const int sd = 23;
const int sck = 18;
const int redLed = 2;
const int greenLed = 22;
const int buttonPin = 21;
int counter = 0;
unsigned int lastPressTime= 0;
bool recording = false;

#define I2S_PORT I2S_NUM_0
int32_t audioBuffer[60];
SPIClass customSPI(VSPI);
File file;

void setup() {
    Serial.begin(115200);
    delay(1000);
    pinMode(buttonPin,INPUT_PULLUP);
    pinMode(redLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    i2s_config_t config {
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
        .sample_rate = 16000,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
        .channel_format = I2S_CHANNEL_FMT_ONLY_RIGHT,
        .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_STAND_I2S),
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
        .dma_buf_count = 8,
        .dma_buf_len = 64,
    };
    i2s_pin_config_t pins {
        .bck_io_num = sck,
        .ws_io_num = ws,
        .data_out_num = I2S_PIN_NO_CHANGE,
        .data_in_num = sd,
    };
    i2s_driver_install(I2S_PORT, &config, 0, NULL);
    i2s_set_pin(I2S_PORT, &pins);
    customSPI.begin(sd_sck, sd_miso, sd_mosi, sd_cs);

    if (SD.begin(sd_cs, customSPI) == false) {
        Serial.println("SD card did not initialize");
        return;
    }
    SD.remove("/test.txt");
    file = SD.open("/test.txt", FILE_WRITE);
    if (!file) {
        Serial.println("file not created");
        return;
    }
    digitalWrite(greenLed,HIGH);
    digitalWrite(redLed,LOW);
}

void loop() {
    Serial.print("button: ");
    Serial.print(digitalRead(buttonPin));
    Serial.print("  recording: ");
    Serial.println(recording);
    if (digitalRead(buttonPin) == LOW) {
        if (millis() - lastPressTime > 300) {
            recording = !recording;
            if (recording == true) {
                SD.remove("/test.txt");
                file = SD.open("/test.txt", FILE_WRITE);
                i2s_zero_dma_buffer(I2S_PORT);
            }
            else {
                file.flush();
                file.close();
            }
        }
        lastPressTime = millis();
    }
    digitalWrite(greenLed, !recording);
    digitalWrite(redLed, recording);
    if (recording == true) {
        size_t bytes = 0;
        i2s_read(I2S_PORT, &audioBuffer, 240, &bytes, portMAX_DELAY);
        if (bytes > 0) {
            file.write((uint8_t*)audioBuffer, bytes);
            counter++;
            if (counter >= 100) {
                file.flush();
                counter = 0;
            }
        }
    }
}