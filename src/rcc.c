#include "rcc.h"
#include "util.h"

void rcc_init(void) {
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC;   //set HSE clock as PLL clock source
    RCC->PLLCFGR &= ~(0x3F);              //clear some reset values
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLM(4);  //set division factor for input clk
    RCC->PLLCFGR &= ~(0x1ff << 6);        //clear reset values
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLN(84); //set multiplication factor
    RCC->PLLCFGR |= RCC_PLLCFGR_PLLP(1);  //set division factor for output (div by 4)
    RCC->CR |= RCC_CR_HSEON; //|  //enable HSE clock

    while (!(RCC->CR & RCC_CR_HSERDY)) {
        delay(1000U);
    }

    //wait for PLL to init
    RCC->CR |= RCC_CR_PLLON;
    while(!(RCC->CR & RCC_CR_PLLRDY)) {
        delay(100U);
    }
    RCC->CFGR |= RCC_CFGR_SW_PLL; //set pll as sys clock
}