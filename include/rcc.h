
#ifndef RCC_H_
#define RCC_H_

#include "config.h"
#include "registers.h"

#if (CONFIG_MCU_TARGET == CONFIG_MCU_L152)
    #define RCC_CR_HSEON (1 << 16)
    #define RCC_CR_HSERDY (1 << 17)
    #define RCC_CR_HSEBYP (1 << 18)
    
    #define RCC_AHBENR_GPIOAEN (1 << 0)
    #define RCC_AHBENR_GPIOHEN (1 << 5)

    #define RCC_CFGR_SW_HSE (1 << 1) /* System clock switch - HSE as system clock*/
#elif (CONFIG_MCU_TARGET == CONFIG_MCU_F411)
    #define RCC_CR_HSEON  (1 << 16)
    #define RCC_CR_HSERDY (1 << 17)
    #define RCC_CR_HSEBYP (1 << 18)

    #define RCC_AHB1ENR_GPIOAEN (1 << 0)

    #define RCC_APB2ENR_SPI1EN (1 << 12) //enable SPI1

    #define RCC_CFGR_SW_HSE (1 << 0)
#else 
    #error "Target MCU not supported!"
#endif /* CONFIG_MCU_TARGET == CONFIG_MCU_L152 */


void rcc_init(void);

#endif /* RCC_H_ */