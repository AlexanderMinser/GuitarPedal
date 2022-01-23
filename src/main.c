/*main.c - main entry point
  author: alex minser */

#include "registers.h"
#include "util.h"
#include "usart.h"
#include "interrupts.h"

int main (void) {
    RCC->CR |= (1 << 16);         //enable HSE clock
    if (RCC->CR & (1 << 17)) {
        #if (CONFIG_MCU_TARGET == CONFIG_MCU_F0R8)
            RCC->CFGR |= (1 << 0);    //set HSE as sys clock
        #elif (CONFIG_MCU_TARGET == CONFIG_MCU_L152)
            RCC->CFGR |= ()
    }
    RCC->AHBENR |= (1 << 17);     //enable GPIO port A
    GPIOA->MODER |= (0x01 << 10); //enable GPIOA pin 5
    //TODO - do I need to disable/feed the watchdog?

    //usart_init();
    while (1) {
        // toggle on board LED
        GPIOA->ODR ^= (1 << 5);
        delay(1000000U);
        //usart_tx_char('a');
    }
}
