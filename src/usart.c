#ifndef UART_C_
#define UART_C_

#include "registers.h"
#include "usart.h"

void usart_init(void) {
    REG(RCC_APB1ENR) |= (1 << 17);   //enable clock to usart2

    //configure number of stop bits in cr2 (bits 12 and 13)
    //reset with RCC_APB1RSTR
    
//1. Program the M bit in USART_CR1 to define the word length.
//2. Select the desired baud rate using the USART_BRR register.
//3. Program the number of stop bits in USART_CR2.
//4. Enable the USART by writing the UE bit in USART_CR1 register to 1.
    REG(USART2_CR1) |= (1 << 3) | (1 << 2) | (1 << 0); //enable tx, rx, and usart
//5. Select DMA enable (DMAT) in USART_CR3 if multibuffer communication is to take
//place. Configure the DMA register as explained in multibuffer communication.
//6. Set the TE bit in USART_CR1 to send an idle frame as first transmission.
//7. Write the data to send in the USART_TDR register (this clears the TXE bit). Repeat this
//for each data to be transmitted in case of single buffer.
//8. After writing the last data into the USART_TDR register, wait until TC=1. This indicates
//that the transmission of the last frame is complete. This is required for instance when
//the USART is disabled or enters the Halt mode to avoid corrupting the last
//transmission.
}

#endif