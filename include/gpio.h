
#ifndef GPIO_H_
#define GPIO_H_

#if (CONFIG_MCU_TARGET == CONFIG_MCU_L152)
    #define GPIO_MODER5(x) ((x) << 10)

    #define GPIO_ODR5 (1 << 5)
#else
    #error "Target MCU not supported!"
#endif

void gpio_init(void);
void toggle_led(void);

#endif /* GPIO_H_ */

