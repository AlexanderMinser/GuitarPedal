
#ifndef RCC_H_
#define RCC_H_

#include "config.h"
#include "registers.h"

#if (CONFIG_MCU_TARGET == CONFIG_MCU_L152)
    #define RCC_CR_HSEON (1 << 16)
    #define RCC_CR_HSERDY (1 << 17)
    
    #define RCC_AHBENR_GPIOAEN (1 << 0)

    #define RCC_CFGR_SW_HSE (1 << 1) /* System clock switch - HSE as system clock*/
#else 
    #error "Target MCU not supported!"
#endif /* CONFIG_MCU_TARGET == CONFIG_MCU_L152 */


void rcc_init(void);

#endif /* RCC_H_ */