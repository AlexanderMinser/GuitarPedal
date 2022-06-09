#include "i2s.h"
#include "rcc.h"
#include "registers.h"
#include "gpio.h"
#include "util.h"
#include "interrupts.h"

//TODO: figure out why I can't write to this
uint32_t i2s_data = 0xffffffff;

void i2s_init(void) {
    /*-PA15  = I2S3_WS
      -PB3  = I2S3_CK
      -PB5  = I2S3_SD
      -PB10 = I2S3_MCK */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //enable GPIO port A
    GPIOA->MODER |= GPIO_MODER15(2);     //set PA15 to alternate function mode

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN; //enable GPIO port B
    GPIOB->MODER |= GPIO_MODER3(2);      //set PB3 to alternate func mode
    GPIOB->MODER |= GPIO_MODER5(2);      //set PB5 to alternate func mode
    GPIOB->MODER |= GPIO_MODER10(2);     //set PB10 to alternate func mode

    RCC->APB1ENR |= RCC_APB1ENR_SPI3EN;  //enable clock to SPI3/I2S3
    
    GPIOA->AFRH |= GPIO_AFRH15_AFy(6); //configure PA15 as I2S3_WS
    GPIOB->AFRL |= GPIO_AFRL3_AFy(6);  //configure PB3 as I2S3_CK 
    GPIOB->AFRL |= GPIO_AFRL5_AFy(6);  //configure PB5 as I2S3_SD
    GPIOB->AFRH |= GPIO_AFRH10_AFy(6); //configure PB10 as I2S3_MCK

    SPI3->I2SCFGR |= SPI_I2SCFGR_I2SMOD; //enable I2S mode
    SPI3->I2SCFGR |= SPI_I2SCFGR_I2SCFG(3); //select i2s master rx mode
    //TODO: configure PCMSYNC 

    SPI3->I2SCFGR |= SPI_I2SCFGR_I2SSTD(0); //enable PCM standard (TODO:verify this!) (I2S phillips std actually)
    SPI3->I2SCFGR |= SPI_I2SCFGR_DATALEN(1); //set data len to 24 bits
    
    // setup bitclock
    RCC->PLLI2SCFGR &= ~(0x3F);
    RCC->PLLI2SCFGR |= RCC_PLLI2SCFGR_PLLI2SM(8); //divide clock down to 1MHz

    //setup PLLI2S clock
    //found from table 90 in ref manual
    RCC->PLLI2SCFGR &= ~(0x1ff << 6);
    RCC->PLLI2SCFGR |= RCC_PLLI2SCFGR_PLLI2SN(213);
    RCC->PLLI2SCFGR &= ~(0x7 << 28);
    RCC->PLLI2SCFGR |= RCC_PLLI2SCFGR_PLLI2SR(2);

    //Test code
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; //enable GPIOC
    GPIOC->MODER |= GPIO_MODER9(2); //set PC9 to alternate func
    //RCC->CFGR |= RCC_CFGR_MCO2_SYS; //set MCO2 output as PLLI2S

    //more bitclock setup
    SPI3->I2SPR |= SPI_I2SPR_I2SDIV(6);
    SPI3->I2SPR |= SPI_I2SPR_ODD;
    
    SPI3->I2SPR |= SPI_I2SPR_MCKOE; //enable i2s master clock output

    //RCC->CR |= RCC_CR_PLLON; //enable PLL clock
    //while (!(RCC->CR & RCC_CR_PLLRDY)) {
    //    delay(1000U);4
    //}

    RCC->CR |= RCC_CR_PLLI2SON;          //enable PLLI2S clock
    //wait for PLLI2SRDY (PLLI2S ready flag)
    while(!(RCC->CR & RCC_CR_PLLI2SRDY)) {
        delay(100);
    }

    NVIC_ISER_1 |= NVIC_ISER_SPI3;
    SPI3->CR2 |= SPI_CR2_RXNEIE; //enable rx buffer not empty irq

    //setup DMA
    
    
    SPI3->I2SCFGR |= SPI_I2SCFGR_I2SE;   //enable I2S
    //i2s_data = SPI3->DR;
}

void i2s_isr(void) {
    uint32_t d_in = 0;
    if (SPI3->SR & SPI_SR_RXNE) { //if rx buf not empty
        d_in = (SPI3->DR & 0x0000ffffu); //read data from rx register
    }
    i2s_data = d_in;
}