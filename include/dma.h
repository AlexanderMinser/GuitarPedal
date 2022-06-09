#ifndef DMA_H_
#define DMA_H_

#include "config.h"

#if (CONFIG_TARGET_MCU == CONFIG_TARGET_F411)
    #define DMA_SxCR_PL_HIGH         (1 << 17)
    #define DMA_SxCR_MSIZE_HALF_WORD (1 << 13)
    #define DMA_SxCR_MINC            (1 << 10)
    #define DMA_SxCR_CIRC            (1 << 8)
    #define DMA_SxCR_EN              (1 << 0)
#else
    #error "Configured target MCU not supported!"
#endif

#endif /* DMA_H_ */