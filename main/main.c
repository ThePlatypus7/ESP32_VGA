#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "i2s_lcd_driver.h"

#define HIGH 4
#define MED 5
#define LOW 1

void app_main(void)
{
    
    gpio_config_t GPIO_HIGH;
    gpio_config_t GPIO_MED;
    gpio_config_t GPIO_LOW;

    GPIO_HIGH.mode = GPIO_MODE_OUTPUT;
    GPIO_HIGH.pin_bit_mask = BIT64(HIGH);
    gpio_config(&GPIO_HIGH);

    GPIO_MED.mode = GPIO_MODE_OUTPUT;
    GPIO_MED.pin_bit_mask = BIT64(MED);
    gpio_config(&GPIO_MED);

    GPIO_LOW.mode = GPIO_MODE_OUTPUT;
    GPIO_LOW.pin_bit_mask = BIT64(LOW);
    gpio_config(&GPIO_LOW);

    while(1){
        gpio_set_level(HIGH,1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(HIGH,0);
        gpio_set_level(MED,1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(MED,0);
        gpio_set_level(LOW,1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(LOW,0);
    }
}
