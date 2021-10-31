#include <string.h>

#include "registers.h"
#include "util.h"
#include "usart.h"

#define CLK_RATE 8000000U
#define USART_BAUD 9600U
#define USART_TX_BUF_SIZE 50

uint8_t tx_buf[USART_TX_BUF_SIZE];
uint8_t curr_tx_idx = 0;

void usart_init(void) {
    RCC->APB1ENR |= (1 << 17);   //enable clock to usart2

    //config GPIO to use USART2 
    //setup UART TX pin
    GPIOA->MODER |= (0x02 << 4);
    GPIOA->AFRL |= (0x01 << 8);
    
//1. Program the M bit in USART_CR1 to define the word length.
    //Reset value is okay (1 start bit, 8 data bits, n stop bits)
//2. Select the desired baud rate using the USART_BRR register.
    USART2->BRR =  CLK_RATE / USART_BAUD;
//3. Program the number of stop bits in USART_CR2.
    //Reset value is okay (1 stop bit)
//4. Enable the USART by writing the UE bit in USART_CR1 register to 1.
    USART2->CR1 |= (1 << 0) | (1 << 3); //enable usart and tx
//5. Select DMA enable (DMAT) in USART_CR3 if multibuffer communication is to take
//place. Configure the DMA register as explained in multibuffer communication.
//6. Set the TE bit in USART_CR1 to send an idle frame as first transmission.
    //USART2->CR1 |= (1 << 3);  //enable tx
//7. Write the data to send in the USART_TDR register (this clears the TXE bit). Repeat this
//for each data to be transmitted in case of single buffer.
    //save this for transmit func
//8. After writing the last data into the USART_TDR register, wait until TC=1. This indicates
//that the transmission of the last frame is complete. This is required for instance when
//the USART is disabled or enters the Halt mode to avoid corrupting the last
//transmission.
}

void usart_tx_char(char c) {
    if (USART2->ISR & (1 << 6)) {
        USART2->ICR |= (1 << 6);
        USART2->TDR = c;
    } else {
        USART2->TDR = c;
    }
}

//TODO: figure out if I want to support strings only or data in general
//      it will change implementation
void usart_tx_str(char* s) {
    uint32_t len = strlen(s);
    if (len < 1 || len > USART_TX_BUF_SIZE) {
        return; //input too small/large
    } else if (left_to_send > 0) {
        return; //not yet done transmitting last string
    }
    strncpy(tx_buf, s, USART_TX_BUF_SIZE);
    curr_tx_idx = 1;
    USART2->TDR = c;
}

void usart_isr(void) {
    if (tx_buf[curr_tx_idx] != '\0') {
        USART2->TDR = tx_buf[curr_tx_idx];
        curr_tx_idx++;
    } else {
        curr_tx_idx = 0;
    }
}