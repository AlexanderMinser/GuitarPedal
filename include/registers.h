#ifndef REGISTERS_H_
#define REGISTERS_H_

#include <stdint.h>

/* Base Addresses for Peripherals */
#define RCC_BASE     0x40021000U
#define GPIOA_BASE   0x48000000U
#define GPIOB_BASE   0x48000400U
#define GPIOC_BASE   0x48000800U
#define GPIOD_BASE   0x48000C00U
#define GPIOF_BASE   0x48001400U
#define USART2_BASE  0x40004400U

//RCC
typedef struct {
    uint32_t CR;
    uint32_t CFGR;
    uint32_t CIR;
    uint32_t APB2RSTR;
    uint32_t APB1RSTR;
    uint32_t AHBENR;
    uint32_t APB2ENR;
    uint32_t APB1ENR;
    uint32_t BDCR;
    uint32_t CSR;
    uint32_t AHBRSTR;
    uint32_t CFGR2;
    uint32_t CFGR3;
    uint32_t CR2;
} RCC_t;

#define RCC ((RCC_t*) RCC_BASE)

//GPIO
typedef struct {
    uint32_t MODER;
    uint32_t OTYPER;
    uint32_t OSPEEDR;
    uint32_t PUPDR;
    uint32_t IDR;
    uint32_t ODR;
    uint32_t BSRR;
    uint32_t LCKR;
    uint32_t AFRL;
    uint32_t AFRH;
    uint32_t BRR;
} GPIO_t;

#define GPIOA ((GPIO_t*) GPIOA_BASE)

//USART
typedef struct {
    uint32_t CR1;
    uint32_t CR2;
    uint32_t CR3;
    uint32_t BRR;
    uint32_t reserved;
    uint32_t RTOR;
    uint32_t RQR;
    uint32_t ISR;
    uint32_t ICR;
    uint32_t RDR;
    uint32_t TDR;
} USART_t;

#define USART2 ((USART_t*) USART2_BASE)

#endif