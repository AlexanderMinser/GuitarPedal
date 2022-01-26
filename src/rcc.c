#include "rcc.h"
#include "util.h"

int8_t bulink = 0;
int8_t blink = 0;

void rcc_init(void) {
    //RCC->AHBENR |= RCC_AHBENR_GPIOHEN; //enable GPIO H (HSE clock source)
    RCC->CR |= RCC_CR_HSEBYP;
    RCC->CR |= RCC_CR_HSEON; //|  //enable HSE clock
               //RCC_CR_HSEBYP;  //bypass internal oscillator with external clock (HSE)

    while (!(RCC->CR & RCC_CR_HSERDY)) {
        //blink = 1;
        delay(1000U);
    }
    RCC->CFGR |= RCC_CFGR_SW_HSE;    //set HSE as sys clock
}