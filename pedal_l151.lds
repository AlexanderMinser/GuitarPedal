ENTRY(_reset_)

MEMORY
{
   flash(RX)  : ORIGIN = 0x08000000, LENGTH = 32K
   sram(WAIL) : ORIGIN = 0x20000000, LENGTH = 16K
}

SECTIONS
{
   .text : { *(.text*) } > flash
   .bss  : { *(.bss*) } > sram
}
