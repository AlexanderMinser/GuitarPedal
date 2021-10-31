#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include <stdint.h>

typedef enum {
    INT_USART2
} interrupt_t;

void interrupt_init(void);
void interrupt_enable(interrupt_t interrupt);
void interrupt_set(interrupt_t interrupt, void* isr, uint8_t priority);

#endif