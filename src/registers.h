#include <stdint.h>

/* Base Addresses for Peripherals */
#define RCC_BASE    0x40021000U
#define GPIOA_BASE  0x48000000U
#define GPIOB_BASE  0x48000400U
#define GPIOC_BASE  0x48000800U
#define GPIOD_BASE  0x48000C00U
#define GPIOF_BASE  0x48001400U


//RCC
#define RCC_CR_OFFSET       0x00U   // Control register for clock and reset control
#define RCC_CFGR_OFFSET     0x04U   // Configuration register for clock and reset control
#define RCC_AHBENR_OFFSET   0x14U   // Offset address for ports
#define RCC_APB2ENR_OFFSET  0x18U   // Offset address for advanced peripheral bus 2
#define RCC_APB1ENR_OFFSET  0x1CU   // Offset address for advanced peripheral bus 1

#define RCC_CR          (RCC_BASE + RCC_CR_OFFSET)
#define RCC_CFGR        (RCC_BASE + RCC_CFGR_OFFSET)
#define RCC_APB1ENR     (RCC_BASE + RCC_APB1ENR_OFFSET)
#define RCC_APB2ENR     (RCC_BASE + RCC_APB2ENR_OFFSET)
#define RCC_AHBENR      (RCC_BASE + RCC_AHBENR_OFFSET)

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

//GPIO
#define GPIOx_ODR           0x14U   // GPIO output data register address
#define GPIOx_IDR           0x10U   // GPIO input data register address
#define GPIOx_MODER         0x00U   // GPIO port mode register address
#define GPIOx_BSRR          0x18U   // GPIO bit SET/RESET registers register address
#define GPIOx_BRR           0x28U   // GPIO port bit reset register
#define GPIOx_OTYPER        0x04U   // GPIO output type register
#define GPIOx_OSPEEDR       0x08U   // GPIO port output speed register
#define GPIOx_PUPDR         0x0CU   // GPIO port pull-up/pull-down register
#define GPIOx_MODER         0x00U   // GPIO mode register

#define GPIOA_MODER     (GPIOA_BASE + GPIOx_MODER)
#define GPIOA_ODR       (GPIOA_BASE + GPIOx_ODR)
#define GPIOA_BSRR      (GPIOA_BASE + GPIOx_BSRR)
#define GPIOA_BRR       (GPIOA_BASE + GPIOx_BRR)

//USART
#define USARTx_CR1          0x00U

#define USART2_CR1          0x40004400U




#define REG(x) (*(unsigned int *)x)