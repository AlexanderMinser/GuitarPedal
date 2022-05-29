
#ifndef GPIO_H_
#define GPIO_H_

#if (CONFIG_MCU_TARGET == CONFIG_MCU_L152)
    #define GPIO_MODER5(x) ((x) << 10)

    #define GPIO_ODR5 (1 << 5)

#elif (CONFIG_MCU_TARGET == CONFIG_MCU_F411)
    #define GPIO_MODER4(x) ((x) << 8)
    #define GPIO_MODER5(x) ((x) << 10)
    #define GPIO_MODER7(x) ((x) << 14)

    #define GPIO_ODR5 (1 << 5)

    //x is pin, y is alternate function
    #define GPIOA_AFRLx_AFy(x, y) ((y) << ((x)*4))
#else
    #error "Target MCU not supported!"
#endif

void gpio_init(void);
void toggle_led(void);

#endif /* GPIO_H_ */

