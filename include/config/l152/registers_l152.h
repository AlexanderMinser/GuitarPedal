#ifndef REGISTERS_L152_H_
#define REGISTERS_L152_H_

#include <stdint.h>

/* Base Addresses for Peripherals */
#define RCC_BASE     0x40023800U
#define GPIOA_BASE   0x40020000U
#define GPIOB_BASE   0x40020400U
#define GPIOC_BASE   0x40020800U
#define GPIOD_BASE   0x40020C00U
#define GPIOE_BASE   0x40021000U
#define GPIOH_BASE   0x40021400U
#define GPIOF_BASE   0x40021800U
#define GPIOG_BASE   0x40021C00U
#define USART2_BASE  0x40004400U

//Base address for NVIC registers
//Found in programming manual
#define NVIC_ISER_BASE    0xE000E100U
#define NVIC_ICER_BASE    0xE000E180U
#define NVIC_ISPR_BASE    0xE000E200U
#define NVIC_ICPR_BASE    0xE000E280U
#define NVIC_IABR_BASE    0xE000E300U
#define NVIC_IPR_BASE     0xE000E400U
#define NVIC_STIR_BASE    0xE000EF00U

//RCC
typedef struct {
    uint32_t CR;
    uint32_t ICSCR;
    uint32_t CFGR;
    uint32_t CIR;
    uint32_t AHBRSTR;
    uint32_t APB2RSTR;
    uint32_t APB1RSTR;
    uint32_t AHBENR;
    uint32_t APB2ENR;
    uint32_t APB1ENR;
    uint32_t AHBLPENR;
    uint32_t APB2LPENR;
    uint32_t APB1LPENR;
    uint32_t CSR;
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
    uint32_t SR;
    uint32_t DR;
    uint32_t BRR;
    uint32_t CR1;
    uint32_t CR2;
    uint32_t CR3;
    uint32_t GTPR;
} USART_t;

#define USART2 ((USART_t*) USART2_BASE)

typedef struct {
    uint32_t CR1;
    uint32_t CR2;
    uint32_t SR;
    uint32_t DR;
    uint32_t CRCPR;
    uint32_t RXCRCR;
    uint32_t TXCRCR;
    uint32_t I2SCFGR;
    uint32_t I2SPR;
} SPI_t;

#define SPIx ((SPI_t*) SPIx_BASE)

//NVIC
#define NVIC_ISER (*((uint32_t*) ISER_BASE))
#define NVIC_ICER (*((uint32_t*) ICER_BASE))
#define NVIC_ISPR (*((uint32_t*) ISPR_BASE))
#define NVIC_ICPR (*((uint32_t*) ICPR_BASE))
#define NVIC_IPR0 (*((uint32_t*) (IPRn_BASE)))
#define NVIC_IPR1 (*((uint32_t*) (IPRn_BASE + sizeof(uint32_t)*1)))
#define NVIC_IPR2 (*((uint32_t*) (IPRn_BASE + sizeof(uint32_t)*2)))
#define NVIC_IPR3 (*((uint32_t*) (IPRn_BASE + sizeof(uint32_t)*3)))
#define NVIC_IPR4 (*((uint32_t*) (IPRn_BASE + sizeof(uint32_t)*4)))
#define NVIC_IPR5 (*((uint32_t*) (IPRn_BASE + sizeof(uint32_t)*5)))
#define NVIC_IPR6 (*((uint32_t*) (IPRn_BASE + sizeof(uint32_t)*6)))
#define NVIC_IPR7 (*((uint32_t*) (IPRn_BASE + sizeof(uint32_t)*7)))

#endif /* REGISTERS_L151_H_ */