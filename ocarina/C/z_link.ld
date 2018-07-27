/* OUTPUT_FORMAT("binary") */
OUTPUT_FORMAT("elf32-bigmips", "elf32-bigmips", "elf32-littlemips")
OUTPUT_ARCH (mips)


rand_hack_addr = 0x802DAD00;  /* 0x801DAFA0; */
memcpy = 0x80057030;
Z_PosMatrix = 0x800AA7F4;
Z_ScaleMatrix = 0x800AA8FC;
Z_RotMatrix = 0x800AAF00;
Z_MovMatrix_POLY_OPA = 0x800AB900;
z_savectx = 0x8011A5D0;
z_staticctx = 0x8011BA00;
Z_SaveGame = 0x800905D4;

MEMORY
{
	ROMSTART (RWXAI) : ORIGIN = (0x802DAD00), LENGTH = 4M
}


SECTIONS
{
	. = rand_hack_addr;
	.start :
	{
		*(.start)
	}
}

/*
0x801DAFA0
SECTIONS
{
	. = rand_hack_addr;
	.text ALIGN(0x10): 
	{
		*(.text*)
	} 
	.data ALIGN(0x10) :
    {
        *(.data*)
	} 
	.rodata ALIGN(0x10) : 
	{
		*(.rodata*)
	} 
	.rel ALIGN(0x10) : 
	{
		*(.rel*)
	} 
	.bss ALIGN(0x10) (NOLOAD): 
	{
		*(.bss*)
		*(.MIPS*)
	} 
}
*/