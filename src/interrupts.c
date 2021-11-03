#include "interrupts.h"
#include "registers.h"

#define USART2_INT_BASE 0x000000B0

void interrupt_enable(interrupt_t interrupt) {
    ISER |= (1 << interrupt);
}

void interrupt_set(interrupt_t interrupt, void* isr, uint8_t priority) {
    //TODO: try to dynamically set this at run time (update vector table)
    *((uint32_t*) 0x000000B0U) = (uint32_t) isr;
}