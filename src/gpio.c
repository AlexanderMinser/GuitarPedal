
#include "gpio.h"
#include "rcc.h"
#include "registers.h"

void gpio_init(void) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //enable GPIO port A
    GPIOA->MODER |= GPIO_MODER5(1);    //enable GPIOA pin 5
}

void toggle_led(void) {
    GPIOA->ODR ^= GPIO_ODR5;//(1 << 5);
}