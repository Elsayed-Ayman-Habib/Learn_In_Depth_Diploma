/*
 * learn-in-dedpth.com
 * Mastering Embedded System online Diploma
 * Eng.Elsayed Ayman Elsayed Ali Habib
 */
 
MEMORY
{
	flash (RX) : ORIGIN = 0x00000000, LENGTH = 512M
	sram (RWX) : ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
	.text : 
	{
		*(.vectors*)
		*(.text*)
		*(.rodata*)
		_E_text = . ;
	} > flash
	
	.data :	
	{
	    _S_DATA = . ;
		*(.data*)
		. = ALIGN(4) ;
		_E_DATA = . ;
	}> sram AT> flash
	
	.bss : 
	{ 
		_S_BSS = . ;
		*(.bss*) 
		. = ALIGN(4) ;
		_E_BSS = . ;
	} > sram
}