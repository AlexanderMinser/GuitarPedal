/*main.c - main entry point
  author: alex minser */

#include "registers.h"
#include "rcc.h"
#include "util.h"
#include "gpio.h"
#include "usart.h"
//#include "interrupts.h"

int main (void) {

    //TODO - do I need to disable/feed the watchdog?

    //usart_init();
    rcc_init();
    gpio_init();
    usart_init();
    while (1) {
        // toggle on board LED
        toggle_led();
        delay(100000U);
        usart_tx_char('a');
    }
}
