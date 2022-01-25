#include "rcc.h"
    
void rcc_init(void) {
   RCC->CR |= RCC_CR_HSEON;         //enable HSE clock
    if (RCC->CR & RCC_CR_HSERDY) {
            RCC->CFGR |= RCC_CFGR_SW_HSE;    //set HSE as sys clock
    }
}
 