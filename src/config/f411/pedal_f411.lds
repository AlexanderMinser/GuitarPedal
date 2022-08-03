ENTRY(_reset_)

MEMORY
{
   flash(RX)  : ORIGIN = 0x08000000, LENGTH = 512K
   sram(WAIL) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
   .text : { *(.text*) } > flash
   .bss  : { *(.bss*) } > sram
   /*.data : { *(.data*) } > sram*/

   /* Used by the startup to initialize data */
   _sidata = LOADADDR(.data);

   /* Initialized data sections into "RAM" Ram type memory */
   .data : 
   {
     . = ALIGN(4);      /* Alignment. */
     _sdata = .;        /* create a global symbol at data start */
     *(.data)           /* .data sections */
     *(.data*)          /* .data* sections */

     . = ALIGN(4);      /* Alignment. */
     _edata = .;        /* define a global symbol at data end */
  
   } >sram AT> flash
}
/*
.bss : 
{
   . = ALIGN(4);
   __START_BSS = .;
   __bss_start__ = .;
   *(.bss)
   *(.bss*)
   *(COMMON)
   . = ALIGN(4);
   __bss_end__ = .;
   __END_BSS = .;
} > m_data */
