/*main.c - main entry point
  author: alex minser */

#include "registers.h"
#include "rcc.h"
#include "util.h"
#include "gpio.h"
#include "usart.h"
#include "i2s.h"
//#include "interrupts.h"

//TODO: to get globals to work, initialize the bss segment to 0
int main (void) {

    //TODO - do I need to disable/feed the watchdog?

    rcc_init();
    gpio_init();
    usart_init();
    i2s_init();

    RCC->CR |= RCC_CR_PLLON;
    while(!(RCC->CR & RCC_CR_PLLRDY)) {
        delay(100U);
    }
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    while (1) {
      // toggle on board LED
      toggle_led();
      delay(10000000U);

      //cd uint32_t clk = RCC->PLLI2SCFGR;
      uint32_t i2s_stuff = i2s_read();
      usart_tx_char(i2s_stuff);
    }
}
