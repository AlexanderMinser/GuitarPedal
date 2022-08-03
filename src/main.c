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
volatile int curr_cnt = 5;
int main (void) {
    rcc_init();
    led_init();
    usart_init();
    //i2s_init();

    while (1) {
      // toggle on board LED
      toggle_led();
      delay(10000000U);
      curr_cnt++;

      //cd uint32_t clk = RCC->PLLI2SCFGR;
      //uint32_t i2s_stuff = i2s_read();
      //usart_tx_char(i2s_stuff);
    }
}
