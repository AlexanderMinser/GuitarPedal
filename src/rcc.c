#include "rcc.h"
#include "util.h"

int8_t bulink = 0;
int8_t blink = 0;

void rcc_init(void) {
    //RCC->AHBENR |= RCC_AHBENR_GPIOHEN; //enable GPIO H (HSE clock source)
    //RCC->CR |= RCC_CR_HSEBYP;
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC;  //set HSE clock as PLL clock source
    RCC->PLLCFGR &= ~(0x3F);
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLM(4);
    RCC->PLLCFGR &= ~(0x1ff << 6);
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLN(84);
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLP(1);
    //RCC->CFGR |= RCC_CFGR_MCO2PRE(6); //divide mco2 by 4
    RCC->CR |= RCC_CR_HSEON; //|  //enable HSE clock

               //RCC_CR_HSEBYP;  //bypass internal oscillator with external clock (HSE)

    while (!(RCC->CR & RCC_CR_HSERDY)) {
        delay(1000U);
    }



    //RCC->CFGR |= RCC_CFGR_SW_HSE;    //set HSE as sys clock
     //set PLL as sys clock
}