/*
 * learn-in-dedpth.com
 * Mastering Embedded System online Diploma
 * Eng.Elsayed Ayman Elsayed Ali Habib
 */
 
 /*
  * Make reset as a global variable in sturtup to be able to access all files
  * .globl reset
  */
 ENTRY(reset)
 
 MEMORY
 {
     /*
	  * rwx -> read , write and execute
	  */
     Mem (rwx) : ORIGIN = 0x00000000, LENGTH = 64M
 }
 
 SECTIONS
 
 {
    /*
	 * to drow memory in your mind the easy way to to it use (dot) 
	 *//*
	   *    -----------
	   *   |  sturtup  |  <- 0x10000
	   *    -----------
	   *   |   Text    |	
       *    -----------		  
	   *   |   Data    |
	   *    -----------
       *   |    bss    |
	   *    -----------
	   *   |    ...    |  <- 0x1000  <- space
	   *    -----------
	   *   | stack_top |
	   *    -----------
	   */
    . = 0x10000;
	/* 
     * ana hena ka2eny b2ol 4ayf el output ely hwa sturtup ana 3yzk tbd2 men el (dot) 3l4an kda ana 7atet (dot) ba3d el output  	
	 */
    .sturtup . :
	{
	  sturtup.o(.text)
	}> Mem
	.text :
	{
	  *(.text) *(.rodata)
	}> Mem
	.data :
	{
	  *(.data)
	}> Mem
	.bss :
	{
	  *(.bss) *(COMMON)
	}> Mem
    . = . + 0x1000;
	stack_top = . ;
 }