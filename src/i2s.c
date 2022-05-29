#include "i2s.h"
#include "rcc.h"
#include "registers.h"
#include "gpio.h"

uint32_t i2s_data = 0xffffffff;

void i2s_init(void) {
    /*-PA15  = I2S3_WS
      -PB3  = I2S3_CK
      -PB5  = I2S3_SD
      -PB10 = I2S3_MCK */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; //enable GPIO port A
    GPIOA->MODER |= GPIO_MODER4(1);      //enable GPIO pin 4
    GPIOA->MODER |= GPIO_MODER5(1);      //enable GPIOA pin 5
    GPIOA->MODER |= GPIO_MODER7(1);      //enable GPIO pin 7

    //RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;   //enable clock to SPI1/I2S1
    
    //GPIOA->AFRL |= GPIOA_AFRLx_AFy(4, 5); //configure GPIOA PA4 as I2S1_WS
    //GPIOA->AFRL |= GPIOA_AFRLx_AFy(5, 5); //configure GPIOA PA5 as I2S1_CK
    //GPIOA->AFRL |= GPIOA_AFRLx_AFy(7, 5); //configure GPIOA PA7 as I2S1_SD

    SPI3->I2SCFGR |= SPI_I2SCFGR_I2SMOD; //enable I2S mode
    SPI3->I2SCFGR |= SPI_I2SCFGR_I2SCFG(3); //select i2s master rx mode
    //TODO: configure PCMSYNC 

    SPI3->I2SCFGR |= SPI_I2SCFGR_I2SSTD(3); //enable PCM standard (TODO:verify this!)
    SPI3->I2SCFGR |= SPI_I2SCFGR_DATALEN(1); //set data len to 24 bits
    
    //TODO: may not need to do this since using diff oscillator for codec now
    SPI3->I2SPR |= SPI_I2SPR_MCKOE; //enable i2s master clock output

    // setup bitclock
    // power up codec(??)

    // send sys clock to codec (prob unnecessary since diff oscillator)
    SPI1->I2SCFGR |= SPI_I2SCFGR_I2SE;   //enable I2S
}

void i2s_read(void) {
    if (SPI1->SR & SPI_SR_RXNE) { //if rx buf not empty
        i2s_data = SPI1->DR; //read data from rx register
    }
}