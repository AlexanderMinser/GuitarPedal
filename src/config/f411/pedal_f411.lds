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
   .data : { *(.data*) } > sram
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
