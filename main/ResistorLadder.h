
#include <stdio.h>
#include "driver/gpio.h"

void ResLad_init(uint8_t highPin, uint8_t mediumPin, uint8_t lowPin);
void ResLad_outputToGPIO(uint8_t value);
void ResLad_resetGPIO();