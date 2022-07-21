
#include "ResistorLadder.h"


gpio_config_t GPIO_HIGH;
gpio_config_t GPIO_MED;
gpio_config_t GPIO_LOW;

uint8_t HIGH = 0;
uint8_t MED = 0;
uint8_t LOW = 0;

void ResLad_init(uint8_t highPin, uint8_t mediumPin, uint8_t lowPin){

    HIGH = highPin;
    MED = mediumPin;
    LOW = lowPin;

    GPIO_HIGH.mode = GPIO_MODE_OUTPUT;
    GPIO_HIGH.pin_bit_mask = BIT64(highPin);
    gpio_config(&GPIO_HIGH);

    GPIO_MED.mode = GPIO_MODE_OUTPUT;
    GPIO_MED.pin_bit_mask = BIT64(mediumPin);
    gpio_config(&GPIO_MED);

    GPIO_LOW.mode = GPIO_MODE_OUTPUT;
    GPIO_LOW.pin_bit_mask = BIT64(lowPin);
    gpio_config(&GPIO_LOW);
}

void ResLad_outputToGPIO(uint8_t value){
    //ResLad_resetGPIO();

    //value = value >> 4;

    gpio_set_level(LOW,value&1 ? 1 : 0);
    gpio_set_level(MED,(value = value >> 1)&1 ? 1 : 0);
    gpio_set_level(HIGH,(value = value >> 1)&1 ? 1 : 0);

}

void ResLad_resetGPIO(){
    gpio_set_level(LOW,0);
    gpio_set_level(MED,0);
    gpio_set_level(HIGH,0);
}

