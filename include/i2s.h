#ifndef I2S_H_
#define I2S_H_

#include "config.h"

#if (CONFIG_TARGET_MCU == CONFIG_TARGET_F411)
    #define SPI_I2SCFGR_I2SMOD (1 << 11)      //I2S mode selection
    #define SPI_I2SCFGR_I2SE   (1 << 10)      //I2S enable
    #define SPI_I2SCFGR_I2SCFG(x) ((x) << 8)  //I2S configuration mode
    #define SPI_I2SCFGR_I2SSTD(x) ((x) << 4)  //I2S standard selection
    #define SPI_I2SCFGR_CKPOL   (1 << 3)      //Steady state clock polarity
    #define SPI_I2SCFGR_DATALEN(x) ((x) << 1) // Data length
    #define SPI_I2SCFGR_CHLEN (1 << 0)        // Channel length
#else
    #error "Configured target mcu not supported!"
#endif /* CONFIG_TARGET_MCU */

void i2s_init(void);
#endif /* I2S_H_ */