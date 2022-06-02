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

    while (1) {
      // toggle on board LED
      toggle_led();
      delay(100000U);

      //uint32_t clk = RCC->PLLI2SCFGR;
      usart_tx_char(clk);
      //i2s_read();
      delay(1000U);
    }
}
