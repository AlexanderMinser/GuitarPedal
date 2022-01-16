# The Cortex M4 is a thumb only processor
.cpu cortex-m4
.syntax unified
.thumb

.word   0x20002000  /* stack top address */
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
.word   spin        /* 16 IRQ0 40*/
.word   spin        /* 17 IRQ1 44*/
.word   spin        /* 18 IRQ2 48*/
.word   spin        /* 19 ...   4C*/
.word   spin        /*50*/
.word   spin        /*54*/
.word   spin        /*58*/
.word   spin        /*5C*/
.word   spin        /*60*/
.word   spin        /*64*/
.word   spin        /*68*/
.word   spin        /*6C*/
.word   spin        /*70*/
.word   spin        /*74*/
.word   spin        /*78*/
.word   spin        /*7C*/
.word   spin        /*80*/
.word   spin        /*84*/
.word   spin        /*88*/
.word   spin        /*8C*/
.word   spin        /*90*/
.word   spin        /*94*/
.word   spin        /*98*/
.word   spin        /*9C*/
.word   spin        /*A0*/
.word   spin        /*A4*/
.word   spin        /*A8*/
.word   spin        /*AC*/
.word   usart_isr   /*USART2 - B0*/
.word   spin        /**/
.word   spin
.word   spin
.word   spin
.word   spin
.word   spin
.word   spin
.word   spin
.word   spin

		            

spin:
    bkpt

.thumb_func
.globl _reset_
_reset_:
    bl main
    bkpt
