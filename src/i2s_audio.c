// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "driver/i2s.h"
// #include "driver/gpio.h"
// #include "esp_log.h"

// #define I2S_NUM         (0)
// #define SAMPLE_RATE     (16000)
// #define SAMPLE_BITS     (16)
// #define I2S_BUF_LEN     (1024)  // samples per read

// #define I2S_BCK_PIN     GPIO_NUM_26
// #define I2S_WS_PIN      GPIO_NUM_25
// #define I2S_DATA_IN_PIN GPIO_NUM_34

// #define LED_PIN         GPIO_NUM_2  // Built-in LED on many ESP32 dev boards

// static const char *TAG = "i2s_audio";

// void i2s_init(void)
// {
//     i2s_config_t i2s_config = {
//         .mode = I2S_MODE_MASTER | I2S_MODE_RX, 
//         .sample_rate = SAMPLE_RATE,
//         .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
//         .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,  // Mono mic on left channel
//         .communication_format = I2S_COMM_FORMAT_STAND_MSB,
//         .intr_alloc_flags = 0,  // default interrupt priority
//         .dma_buf_count = 4,
//         .dma_buf_len = 256,
//         .use_apll = false,
//         .tx_desc_auto_clear = false,
//         .fixed_mclk = 0,
//     };

//     i2s_pin_config_t pin_config = {
//         .bck_io_num = I2S_BCK_PIN,
//         .ws_io_num = I2S_WS_PIN,
//         .data_out_num = GPIO_NUM_35,
//         .data_in_num = I2S_DATA_IN_PIN,
//     };

//     ESP_ERROR_CHECK(i2s_driver_install(I2S_NUM, &i2s_config, 0, NULL));
//     ESP_ERROR_CHECK(i2s_set_pin(I2S_NUM, &pin_config));
//     ESP_LOGI(TAG, "I2S driver installed");
// }

// void i2s_read_task(void *arg)
// {
//     int16_t i2s_read_buf[I2S_BUF_LEN];
//     size_t bytes_read;

//     // Configure LED pin
//     gpio_reset_pin(LED_PIN);
//     gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

//     while (1) {
//         esp_err_t ret = i2s_read(I2S_NUM, (void*)i2s_read_buf, sizeof(i2s_read_buf), &bytes_read, portMAX_DELAY);
//         if (ret == ESP_OK && bytes_read > 0) {
//             int samples_read = bytes_read / sizeof(int16_t);

//             ESP_LOGI(TAG, "Read %d samples, first 8: %d %d %d %d %d %d %d %d",
//                 samples_read,
//                 i2s_read_buf[0], i2s_read_buf[1], i2s_read_buf[2], i2s_read_buf[3],
//                 i2s_read_buf[4], i2s_read_buf[5], i2s_read_buf[6], i2s_read_buf[7]);

//             // Toggle LED on successful read
//             gpio_set_level(LED_PIN, 1);
//             vTaskDelay(pdMS_TO_TICKS(100));
//             gpio_set_level(LED_PIN, 0);
//         } else {
//             ESP_LOGW(TAG, "i2s_read failed: %d", ret);
//             vTaskDelay(pdMS_TO_TICKS(500)); // Wait before retry
//         }
//     }
// }

// void i2s_main(void)
// {
//     i2s_init();
//     xTaskCreate(i2s_read_task, "i2s_read_task", 4096, NULL, 5, NULL);
// }
