#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/i2s.h"

#define BLINK_GPIO GPIO_NUM_2  // onboard LED pin

void app_main(void)
{
    
    esp_rom_gpio_pad_select_gpio(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);


    while (1) {
        gpio_set_level(BLINK_GPIO, 1); // LED ON
        vTaskDelay(800 / portTICK_PERIOD_MS);
        gpio_set_level(BLINK_GPIO, 0); // LED OFF
        vTaskDelay(800 / portTICK_PERIOD_MS);
    }
}
