/*main.c - main entry point
  author: alex minser */

#include "registers.h"

/* spin for some amount of ticks */
void delay(unsigned volatile int t) {
    for (unsigned volatile int i = 0; i < t; i++);
}

int main (void) {
    REG(RCC_CR) |= (1 << 16);          //enable HSE clock
    if (REG(RCC_CR) & (1 << 17)) {
        REG(RCC_CFGR) |= (1 << 0);     //set HSE as sys clock
    }
    REG(RCC_AHBENR) |= (1 << 17);      //enable GPIO port A
    REG(GPIOA_MODER) |= (0x01 << 10);

    //TODO - do I need to disable/feed the watchdog?

    while (1) {
        // toggle on board LED
        REG(GPIOA_ODR) ^= (1 << 5);
        delay(1000000U);
    }
}
