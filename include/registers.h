#ifndef REGISTERS_H_
#define REGISTERS_H

#include "config.h"

#if (CONFIG_MCU_TARGET == CONIFG_MCU_F0R8)
    #include "registers_f0r8.h"
#elif (CONFIG_MCU_TARGET == CONFIG_MCU_L152)
    #include "registers_l152.h"
#elif (CONFIG_MCU_TARGET == CONFIG_MCU_F302)
    #include "registers_f302.h"
#elif (CONFIG_MCU_TARGET == CONFIG_MCU_F411)
    #include "registers_f411.h"
#else
    #error "No processor selected!"
#endif

#endif /* REGISTERS_H_ */