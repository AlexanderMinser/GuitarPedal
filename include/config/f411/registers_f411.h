#ifndef REGISTERS_F411_H_
#define REGISTERS_F411_H_

#include <stdint.h>

#define GPIOA_BASE  (0x40020000U)
#define RCC_BASE    (0x40023800U)
#define USART2_BASE (0x40004400U)
#define SPI1_BASE   (0x40013000U)


// RCC
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


// GPIO
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


// USART
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


// SPI/I2S
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
} SPI_t

#define SPI1 ((SPI_t*) SPI1_BASE) 


//NVIC
//Base address for NVIC registers
//Found in programming manual
#define NVIC_ISER_BASE    0xE000E100U
#define NVIC_ICER_BASE    0xE000E180U
#define NVIC_ISPR_BASE    0xE000E200U
#define NVIC_ICPR_BASE    0xE000E280U
#define NVIC_IABR_BASE    0xE000E300U
#define NVIC_IPR_BASE     0xE000E400U
#define NVIC_STIR_BASE    0xE000EE00U

#define NVIC_ISER_0 (*((uint32_t*) NVIC_ISER_BASE))
#define NVIC_ISER_1 (*((uint32_t*) (NVIC_ISER_BASE + sizeof(uint32_t)*1)))
#define NVIC_ISER_2 (*((uint32_t*) (NVIC_ISER_BASE + sizeof(uint32_t)*2)))
#define NVIC_ISER_3 (*((uint32_t*) (NVIC_ISER_BASE + sizeof(uint32_t)*3)))
#define NVIC_ISER_4 (*((uint32_t*) (NVIC_ISER_BASE + sizeof(uint32_t)*4)))
#define NVIC_ISER_5 (*((uint32_t*) (NVIC_ISER_BASE + sizeof(uint32_t)*5)))
#define NVIC_ISER_6 (*((uint32_t*) (NVIC_ISER_BASE + sizeof(uint32_t)*6)))
#define NVIC_ISER_7 (*((uint32_t*) (NVIC_ISER_BASE + sizeof(uint32_t)*7)))

#define NVIC_ICER_0 (*((uint32_t*) NVIC_ICER_BASE))
#define NVIC_ICER_1 (*((uint32_t*) (NVIC_ICER_BASE + sizeof(uint32_t*1))))
#define NVIC_ICER_2 (*((uint32_t*) (NVIC_ICER_BASE + sizeof(uint32_t*2))))
#define NVIC_ICER_3 (*((uint32_t*) (NVIC_ICER_BASE + sizeof(uint32_t*3))))
#define NVIC_ICER_4 (*((uint32_t*) (NVIC_ICER_BASE + sizeof(uint32_t*4))))
#define NVIC_ICER_5 (*((uint32_t*) (NVIC_ICER_BASE + sizeof(uint32_t*5))))
#define NVIC_ICER_6 (*((uint32_t*) (NVIC_ICER_BASE + sizeof(uint32_t*6))))
#define NVIC_ICER_7 (*((uint32_t*) (NVIC_ICER_BASE + sizeof(uint32_t*7))))

#define NVIC_ISPR_0 (*((uint32_t*) NVIC_ISPR_BASE))
#define NVIC_ISPR_1 (*((uint32_t*) (NVIC_ISPR_BASE + sizeof(uint32_t)*1)))
#define NVIC_ISPR_2 (*((uint32_t*) (NVIC_ISPR_BASE + sizeof(uint32_t)*2)))
#define NVIC_ISPR_3 (*((uint32_t*) (NVIC_ISPR_BASE + sizeof(uint32_t)*3)))
#define NVIC_ISPR_4 (*((uint32_t*) (NVIC_ISPR_BASE + sizeof(uint32_t)*4)))
#define NVIC_ISPR_5 (*((uint32_t*) (NVIC_ISPR_BASE + sizeof(uint32_t)*5)))
#define NVIC_ISPR_6 (*((uint32_t*) (NVIC_ISPR_BASE + sizeof(uint32_t)*6)))
#define NVIC_ISPR_7 (*((uint32_t*) (NVIC_ISPR_BASE + sizeof(uint32_t)*7)))

#define NVIC_ICPR_0 (*((uint32_t*) NVIC_ICPR_BASE))
#define NVIC_ICPR_1 (*((uint32_t*) (NVIC_ICPR_BASE + sizeof(uint32_t)*1)))
#define NVIC_ICPR_2 (*((uint32_t*) (NVIC_ICPR_BASE + sizeof(uint32_t)*2)))
#define NVIC_ICPR_3 (*((uint32_t*) (NVIC_ICPR_BASE + sizeof(uint32_t)*3)))
#define NVIC_ICPR_4 (*((uint32_t*) (NVIC_ICPR_BASE + sizeof(uint32_t)*4)))
#define NVIC_ICPR_5 (*((uint32_t*) (NVIC_ICPR_BASE + sizeof(uint32_t)*5)))
#define NVIC_ICPR_6 (*((uint32_t*) (NVIC_ICPR_BASE + sizeof(uint32_t)*6)))
#define NVIC_ICPR_7 (*((uint32_t*) (NVIC_ICPR_BASE + sizeof(uint32_t)*7)))

#define NVIC_IABR_0 (*((uint32_t*) NVIC_IABR_BASE))
#define NVIC_IABR_1 (*((uint32_t*) (NVIC_IABR_BASE + sizeof(uint32_t)*1)))
#define NVIC_IABR_2 (*((uint32_t*) (NVIC_IABR_BASE + sizeof(uint32_t)*2)))
#define NVIC_IABR_3 (*((uint32_t*) (NVIC_IABR_BASE + sizeof(uint32_t)*3)))
#define NVIC_IABR_4 (*((uint32_t*) (NVIC_IABR_BASE + sizeof(uint32_t)*4)))
#define NVIC_IABR_5 (*((uint32_t*) (NVIC_IABR_BASE + sizeof(uint32_t)*5)))
#define NVIC_IABR_6 (*((uint32_t*) (NVIC_IABR_BASE + sizeof(uint32_t)*6)))
#define NVIC_IABR_7 (*((uint32_t*) (NVIC_IABR_BASE + sizeof(uint32_t)*7)))

#define NVIC_IPR0 (*((uint32_t*) (NVIC_IPR_BASE)))
#define NVIC_IPR1 (*((uint32_t*) (NVIC_IPR_BASE + sizeof(uint32_t)*1)))
#define NVIC_IPR2 (*((uint32_t*) (NVIC_IPR_BASE + sizeof(uint32_t)*2)))
#define NVIC_IPR3 (*((uint32_t*) (NVIC_IPR_BASE + sizeof(uint32_t)*3)))
#define NVIC_IPR4 (*((uint32_t*) (NVIC_IPR_BASE + sizeof(uint32_t)*4)))
#define NVIC_IPR5 (*((uint32_t*) (NVIC_IPR_BASE + sizeof(uint32_t)*5)))
#define NVIC_IPR6 (*((uint32_t*) (NVIC_IPR_BASE + sizeof(uint32_t)*6)))
#define NVIC_IPR7 (*((uint32_t*) (NVIC_IPR_BASE + sizeof(uint32_t)*7)))

#endif /* REGISTERS_F411_H_ */