#ifndef REGISTERS_F0R8_H_
#define REGISTERS_F0R8_H_

#include <stdint.h>

/* Base Addresses for Peripherals */
#define RCC_BASE     0x40021000U
#define GPIOA_BASE   0x48000000U
#define GPIOB_BASE   0x48000400U
#define GPIOC_BASE   0x48000800U
#define GPIOD_BASE   0x48000C00U
#define GPIOF_BASE   0x48001400U
#define USART2_BASE  0x40004400U
#define EXTI_BASE    0x40010400U

//Base address for NVIC registers
#define ISER_BASE    0xE000E100U
#define ICER_BASE    0xE000E180U
#define ISPR_BASE    0xE000E200U
#define ICPR_BASE    0xE000E280U
#define IPRn_BASE    0xE000E400U

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

//EXTI
typedef struct {
    uint32_t IMR;
    uint32_t EMR;
    uint32_t RTSR;
    uint32_t FTSR;
    uint32_t SWIER;
    uint32_t PR;
} EXTI_t;

#define EXTI ((EXTI_t*) EXTI_BASE)

//NVIC
#define ISER (*((uint32_t*) ISER_BASE))
#define ICER (*((uint32_t*) ICER_BASE))
#define ISPR (*((uint32_t*) ISPR_BASE))
#define ICPR (*((uint32_t*) ICPR_BASE))
#define IPR0 (*((uint32_t*) (IPRn_BASE)))
#define IPR1 (*((uint32_t*) (IPRn_BASE + sizeof(uint32_t)*1)))
#define IPR2 (*((uint32_t*) (IPRn_BASE + sizeof(uint32_t)*2)))
#define IPR3 (*((uint32_t*) (IPRn_BASE + sizeof(uint32_t)*3)))
#define IPR4 (*((uint32_t*) (IPRn_BASE + sizeof(uint32_t)*4)))
#define IPR5 (*((uint32_t*) (IPRn_BASE + sizeof(uint32_t)*5)))
#define IPR6 (*((uint32_t*) (IPRn_BASE + sizeof(uint32_t)*6)))
#define IPR7 (*((uint32_t*) (IPRn_BASE + sizeof(uint32_t)*7)))

#endif /* REGISTERS_F0R8_H_ */