#ifndef REGISTERS_H_
#define REGISTERS_H

#if (TARGET_MCU == STM32_F0R8)
    #include "registers_f0r8.h"
#elif (TARGET_MCU == STM32_L151)
    #include "registers_l151.h"
#else
    #error "No processor selected!"
#endif

#endif /* REGISTERS_H_ */