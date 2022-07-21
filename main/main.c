#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "i2s_lcd_driver.h"
#include "ResistorLadder.h"


void app_main(void)
{
    

    ResLad_init(1, 5, 4);
    

    uint8_t val = 0;
    while(1){

        vTaskDelay(1 / portTICK_PERIOD_MS);
        ResLad_outputToGPIO(val);
        val++;
        if(val == 8){
            val = 0;
        }

    }
}
