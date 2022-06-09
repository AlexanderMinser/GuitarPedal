#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include <stdint.h>
#include "config.h"

#if (CONFIG_TARGET_MCU == CONFIG_TARGET_F411)
    #define NVIC_ISER_SPI3 (1 << 19)
#else
    #error "Configured target MCU not supported!"
#endif

typedef enum {
    INT_USART2 = 38//28
} interrupt_t;

void interrupt_init(void);
void interrupt_enable(interrupt_t interrupt);
void interrupt_set(interrupt_t interrupt, void* isr, uint8_t priority);

#endif