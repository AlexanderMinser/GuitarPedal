#ifndef REGISTERS_F411_H_
#define REGISTERS_F411_H_

#include <stdint.h>

#define GPIOA_BASE  0x40020000U
#define RCC_BASE    0x40023800U
#define USART2_BASE 0x40004400U

typedef struct {
    uint32_t CR;
    uint32_t PLLCFGR;
    uint32_t CFGR;
    uint32_t CIR;
    uint32_t AHB1RSTR;
    uint32_t AHB2RSTR;
    uint32_t reserved[2];
    uint32_t APB1RSTR;
    uint32_t APB2RSTR;
    uint32_t reserved2[2];
    uint32_t AHB1ENR;
    uint32_t AHB2ENR;
    uint32_t reserved3[2];
    uint32_t APB1ENR;
    uint32_t APB2ENR;
    uint32_t reserved4[2];
    uint32_t AHB1LPENR;
    uint32_t AHB2LPENR;
    uint32_t reserved5[2];
    uint32_t APB1LPENR;
    uint32_t APB2LPENR;
    uint32_t reserved6[2];
    uint32_t BDCR;
    uint32_t CSR;
    uint32_t reserved7[2];
    uint32_t SSCGR;
    uint32_t PLLI2SCFGR; 
    uint32_t reserved8;
    uint32_t DCKCFGR;
} RCC_t;

#define RCC ((RCC_t*) RCC_BASE)

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
} GPIO_t;

#define GPIOA ((GPIO_t*) GPIOA_BASE)

typedef struct {
    uint32_t SR;
    uint32_t DR;
    uint32_t BRR;
    uint32_t CR1;
    uint32_t CR2;
    uint32_t CR3;
    uint32_t GTPR;
} USART_t;

#define USART2 ((USART_t*) USART2_BASE)

#endif /* REGISTERS_F411_H_ */