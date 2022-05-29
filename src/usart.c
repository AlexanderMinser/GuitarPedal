#include <string.h>

#include "registers.h"
#include "util.h"
#include "usart.h"
#include "interrupts.h"


//#define CLK_RATE 8000000U //f0r8
#if (CONFIG_TARGET_MCU == CONFIG_TARGET_F411)
    #define CLK_RATE  8000000U
#endif
//#define CLK_RATE 2097000U
#define USART_BAUD 9600U
#define USART_TX_BUF_SIZE 50

char tx_buf[USART_TX_BUF_SIZE];
uint8_t curr_tx_idx = 0;

void usart_init(void) {
    //interrupt_set(0, usart_isr, 0);
    interrupt_enable(INT_USART2);

    RCC->APB1ENR |= (1 << 17);   //enable clock to usart2

    //config GPIO to use USART2 
    //setup UART TX pin
    GPIOA->MODER |= (0x02 << 4);
    GPIOA->AFRL |= (7 << 8);//(0x01 << 8);
    
    //Select the desired baud rate using the USART_BRR register.
    USART2->BRR |=  ((CLK_RATE / (USART_BAUD * 8 * 2)) << 4) | 1;

    USART2->CR1 |= USART_CR1_UE | USART_CR1_TE | USART_CR1_TXEIE; //enable usart, tx, and tx irq
}

void usart_tx_char(char c) {
    if (USART2->SR & USART_SR_TC) {
       // USART2->ICR |= (1 << 6);
        USART2->DR = c;
    } else {
        USART2->DR = c;
    }
}

//TODO: figure out if I want to support strings only or data in general
//      it will change implementation
void usart_tx_str(char* s) {
    uint32_t len = strlen(s);
    if (len < 1 || len > USART_TX_BUF_SIZE) {
        return; //input too small/large
    } else if (curr_tx_idx > 0) {
        return; //not yet done transmitting last string
    }
    strncpy(tx_buf, s, USART_TX_BUF_SIZE);
    curr_tx_idx = 1;
    USART2->DR = s[0];
}

void usart_isr(void) {
    if (tx_buf[curr_tx_idx] != '\0') {
        USART2->DR = tx_buf[curr_tx_idx];
        curr_tx_idx++;
    } else {
        curr_tx_idx = 0;
    }
}