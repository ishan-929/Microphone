#include <Arduino.h>
#include <driver/i2s.h>

const int ws = 25;
const int sd = 33;
const int sck = 26;

#define I2S_PORT I2S_NUM_0

void setup() {
    Serial.begin(115200);
    i2s_config_t config = {
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
        .sample_rate = 16000,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
        .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
        .communication_format = I2S_COMM_FORMAT_I2S_MSB,
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
        .dma_buf_count = 8,
        .dma_buf_len = 64,
    };
    i2s_pin_config_t pins = {
        .bck_io_num = sck,
        .ws_io_num = ws,
        .data_out_num = -1,
        .data_in_num = sd
    };
    i2s_driver_install(I2S_PORT, &config, 0, NULL);
    i2s_set_pin(I2S_PORT, &pins);
}

void loop() {
    int32_t samples[64];
    size_t bytesRead;

    i2s_read(I2S_PORT, samples, sizeof(samples), &bytesRead, portMAX_DELAY);
    long volume = 0;
    for (int i = 0; i < 64; i++) {
        volume = volume + abs(samples[i]);
    }
    Serial.println(volume/64);
}