#include "interrupts.h"
#include "registers.h"

#define USART2_INT_BASE 0x000000B0U

void interrupt_enable(interrupt_t interrupt) {
    NVIC_ISER_1 |= (1 << 6); //usart2 isr
}

void interrupt_set(interrupt_t interrupt, void* isr, uint8_t priority) {
    //TODO: try to dynamically set this at run time (update vector table)
    *((uint32_t*) 0x000000B0U) = (uint32_t) isr;
}