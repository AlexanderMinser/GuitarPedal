#ifndef REGISTERS_H_
#define REGISTERS_H

#if (TARGET_MCU == STM32_F0R8)
    #include "registers_f0r8.h"
#elif (TARGET_MCU == STM32_L152)
    #include "registers_l152.h"
#elif (TARGET_MCU == STM32_F302)
    #include "registers_f302.h"
#else
    #error "No processor selected!"
#endif

#endif /* REGISTERS_H_ */