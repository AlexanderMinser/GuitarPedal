#ifndef UART_H_
#define UART_H_

#include <stdbool.h>

void usart_init(void);
bool usart_tx(char c);

#endif