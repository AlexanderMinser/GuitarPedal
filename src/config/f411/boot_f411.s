# The Cortex M4 is a thumb processor
.cpu cortex-m4
.syntax unified
.thumb

/*Don't trust these isr comments!*/
.word   0x20020000  /* stack top address 
                       TODO: double check this for new processor*/
.word   _reset_     /* 1 Reset */
.word   spin        /* 2 NMI */
.word   spin        /* 3 Hard Fault */
.word   spin        /* 4 MM Fault */
.word   spin        /* 5 Bus Fault */
.word   spin        /* 6 Usage Fault */
.word   spin        /* 7 RESERVED */
.word   spin        /* 8 RESERVED */
.word   spin        /* 9 RESERVED*/
.word   spin        /* 10 RESERVED */
.word   spin        /* 11 SV call - 2C */
.word   spin        /* 12 Debug reserved */
.word   spin        /* 13 RESERVED */
.word   spin        /* 14 PendSV */
.word   spin        /* 15 SysTick - 3C */
.word   spin        /* 16 WWDG */
.word   spin        /* 17 PVD*/
.word   spin        /* 18 TAMPER STAMP */
.word   spin        /* 19 RTC_WKUP */
.word   spin        /*50 FLASH */
.word   spin        /*54 RCC */
.word   spin        /*58 EXTI0  */
.word   spin        /*5C EXTI1 */
.word   spin        /*60 EXTI2 */
.word   spin        /*64 EXTI3 */
.word   spin        /*68 EXTI4 */
.word   spin        /*6C DMA1_Channel1 */
.word   spin        /*70 DMA1_Channel2 */
.word   spin        /*74 DMA1_Channel3 */
.word   spin        /*78 DMA1_Channel4 */
.word   spin        /*7C DMA1_Channel5 */
.word   spin        /*80 DMA1_Channel6 */
.word   spin        /*84 DMA1_Channel7 */
.word   spin        /*88 ADC1 */
.word   spin        /*8C USB HP */
.word   spin        /*90 USB LP */
.word   spin        /*94 DAC */
.word   spin        /*98 COMP, TSC*/
.word   spin        /*9C EXTI9_5 */
.word   spin        /*A0 LCD */
.word   spin        /*A4 TIM9 */
.word   spin        /*A8 TIM10 */
.word   spin        /*AC TIM11 */
.word   spin        /*TIM2 */
.word   spin        /*TIM3*/
.word   spin        /*TIM4 */
.word   spin        /*I2C1_EV */
.word   spin        /*I2C1_ER */
.word   spin        /*I2C2_EV */
.word   spin        /*I2C2_ER */
.word   spin        /*SPI1 */
.word   spin        /*SPI2 */
.word   spin        /*USART1 */
.word   usart_isr        /*USART2 */
.word   spin        /*reserved */
.word   spin        /*EXTI5_10 */
.word   spin        /*RTC_Alarm */
.word   spin        /*OTG_FS_WKUP */
.rept   4
.word   spin        /*reserved*/
.endr
.word   spin        /*DMA1_Stream7*/
.word   spin        /*reserved */
.word   spin        /*SDIO */
.word   spin        /*TIM5 */
.word   i2s_isr     /*SPI3*/
.word   spin        /* */
.word   spin        /* */
.word   spin        /* */
.word   spin        /* */
.word   spin        /* */
.word   spin        /* */
.word   spin        /* */
.word   spin        /* */
.word   spin        /* */
.word   spin        /* */
.word   spin        /* */

		            

spin:
    bkpt

.thumb_func
.globl _reset_
_reset_:
    bl main
    bkpt
