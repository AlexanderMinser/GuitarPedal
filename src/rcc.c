#include "rcc.h"
#include "util.h"

int8_t bulink = 0;
int8_t blink = 0;

void rcc_init(void) {
    //RCC->AHBENR |= RCC_AHBENR_GPIOHEN; //enable GPIO H (HSE clock source)
    //RCC->CR |= RCC_CR_HSEBYP;
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC;  //set HSE clock as PLL clock source
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLN(10); //bump PLL output x10 (80MHz)
    RCC->CR |= RCC_CR_HSEON; //|  //enable HSE clock

               //RCC_CR_HSEBYP;  //bypass internal oscillator with external clock (HSE)

    while (!(RCC->CR & RCC_CR_HSERDY)) {
        //blink = 1;
        delay(1000U);
    }

    RCC->CFGR |= RCC_CFGR_SW_HSE;    //set HSE as sys clock
    //TODO: RCC->CFGR |= RCC_CFGR_SW_PLL; //set PLL as sys clock
}