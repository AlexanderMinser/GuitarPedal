
#include "registers.h"
#include "util.h"
#include "usart.h"

#define CLK_RATE 8000000U
#define USART_BAUD 115200U

void usart_init(void) {
    RCC->APB1ENR |= (1 << 17);   //enable clock to usart2

    //reset with RCC_APB1RSTR
    
//1. Program the M bit in USART_CR1 to define the word length.
    //Reset value is okay (1 start bit, 8 data bits, n stop bits)
//2. Select the desired baud rate using the USART_BRR register.
    USART2->BRR =  CLK_RATE / USART_BAUD;
//3. Program the number of stop bits in USART_CR2.
    //Reset value is okay (1 stop bit)
//4. Enable the USART by writing the UE bit in USART_CR1 register to 1.
    USART2->CR1 |= (1 << 0); //enable usart
//5. Select DMA enable (DMAT) in USART_CR3 if multibuffer communication is to take
//place. Configure the DMA register as explained in multibuffer communication.
//6. Set the TE bit in USART_CR1 to send an idle frame as first transmission.
    USART2->CR1 |= (1 << 3); //enable tx
//7. Write the data to send in the USART_TDR register (this clears the TXE bit). Repeat this
//for each data to be transmitted in case of single buffer.
    //save this for transmit func
//8. After writing the last data into the USART_TDR register, wait until TC=1. This indicates
//that the transmission of the last frame is complete. This is required for instance when
//the USART is disabled or enters the Halt mode to avoid corrupting the last
//transmission.
}

bool usart_tx(char c) {
    USART2->TDR = c;
    delay(100);
    if (USART2->ISR & (1 << 6)) {
        return true; //tx success
    } else {
        return false; //tx fail
    }
}