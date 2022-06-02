
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
    #define RCC_CR_HSEON    (1 << 16)
    #define RCC_CR_HSERDY   (1 << 17)
    #define RCC_CR_HSEBYP   (1 << 18)
    #define RCC_CR_PLLON    (1 << 24)
    #define RCC_CR_PLLRDY   (1 << 25)
    #define RCC_CR_PLLI2SON (1 << 26)
    #define RCC_CR_PLLI2SRDY (1 << 27)

    #define RCC_AHB1ENR_GPIOAEN (1 << 0)
    #define RCC_AHB1ENR_GPIOBEN (1 << 1)
    #define RCC_AHB1ENR_GPIOCEN (1 << 2)

    #define RCC_APB1ENR_SPI3EN (1 << 15)

    #define RCC_APB2ENR_SPI1EN (1 << 12) //enable SPI1

    #define RCC_CFGR_SW_HSE (1 << 0)
    #define RCC_CFGR_MCO2_HSE (2 << 30)
    #define RCC_CFGR_MCO2_PLLI2S (1 << 30)

    #define RCC_PLLCFGR_PLLSRC (1 << 22)
    #define RCC_PLLCFGR_PLLN(x) ((x) << 6)

    #define RCC_PLLI2SCFGR_PLLI2SM(x) ((x) << 0)
    #define RCC_PLLI2SCFGR_PLLI2SN(x) ((x) << 6)
    #define RCC_PLLI2SCFGR_PLLI2SR(x) ((x) << 28)
#else 
    #error "Target MCU not supported!"
#endif /* CONFIG_MCU_TARGET == CONFIG_MCU_L152 */


void rcc_init(void);

#endif /* RCC_H_ */