ENTRY(_reset_)

MEMORY
{
   flash(RX)  : ORIGIN = 0x08000000, LENGTH = 64K
   sram(WAIL) : ORIGIN = 0x20000000, LENGTH = 8K
}

SECTIONS
{
   .text : { *(.text*) } > flash
   .bss  : { *(.bss*) } > sram
}
