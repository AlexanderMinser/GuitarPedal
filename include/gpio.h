
#ifndef GPIO_H_
#define GPIO_H_

#include "config.h"

#if (CONFIG_MCU_TARGET == CONFIG_MCU_L152)
    #define GPIO_MODER5(x) ((x) << 10)

    #define GPIO_ODR5 (1 << 5)

#elif (CONFIG_MCU_TARGET == CONFIG_MCU_F411)
    #define GPIO_MODER3(x) ((x) << 6)
    #define GPIO_MODER4(x) ((x) << 8)
    #define GPIO_MODER5(x) ((x) << 10)
    #define GPIO_MODER7(x) ((x) << 14)
    #define GPIO_MODER9(x) ((x) << 18)
    #define GPIO_MODER10(x) ((x) << 20)
    #define GPIO_MODER15(x) ((x) << 30)

    #define GPIO_ODR5 (1 << 5)

    #define GPIO_AFRL3_AFy(y) ((y) << 12)
    #define GPIO_AFRL5_AFy(y) ((y) << 20)

    #define GPIO_AFRH10_AFy(y) ((y) << 8)
    #define GPIO_AFRH15_AFy(y) ((y) << 28)
#else
    #error "Target MCU not supported!"
#endif

void led_init(void);
void toggle_led(void);

#endif /* GPIO_H_ */

