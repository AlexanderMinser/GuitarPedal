#ifndef UART_H_
#define UART_H_

#include "config.h"

#if (CONFIG_MCU_TARGET == CONFIG_MCU_L152)
    #define USART_SR_TC (1 << 6)

    #define USART_CR1_UE (1 << 13)    //USART enable
    #define USART_CR1_TXEIE (1 << 7)  //Transmit interrupt enable
    #define USART_CR1_TE (1 << 3)     //Transmitter enable
#elif (CONFIG_MCU_TARGET == CONFIG_MCU_F411)
    #define USART_SR_TC (1 << 6)      //Transmission complete

    #define USART_CR1_UE (1 << 13)    //USART enable
    #define USART_CR1_TXEIE (1 << 7)  //Transmit interrupt enable
    #define USART_CR1_TE (1 << 3)     //Transmitter enable
#else
    #error "No configured target mcu!"
#endif

void usart_init(void);
void usart_tx_char(char c);
void usart_isr(void);

#endif