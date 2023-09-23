/*
 * learn-in-dedpth.com
 * Mastering Embedded System online Diploma
 * Eng.Elsayed Ayman Elsayed Ali Habib
 */
 
#include  <stdint.h>

/*
 * ana hena lw ana 3mlt array 5letha t4awer 3ala awl mkan fe el rom 
/*
	   /*    -----------
	   *   |  sturtup  |  
	   *    -----------
	   *   |   Text    |	
       *    -----------		  
	   *   |   Data    |
	   *    -----------
       *   |    bss    |
	   *    -----------
	   *   |    ...    | 
	   *    -----------
	   *   | stack_top |
	   *    -----------
	   * f kda ana 3mlt access bel array 5leto y4awer 3ala el2makn de fe el rom 
	   */

void Reset_Handler (void);
void Default_Handler (void)
{
	Reset_Handler();
}
/*
 * weak -> get me option taht i can implemante the function with anthor implemantation not the same with the origin implemantation 
 * alias -> make that simpols have the same address until using this function
 * to use this functions in main.c -> use extern
 */
void NMI_Handler (void) __attribute__((weak,alias("Default_Handler")));       
void HardFault_Handler (void)__attribute__((weak,alias("Default_Handler")));        
/*
 * ana azay a3rf an el array de m4 data section 
 * w a3rfo en de asmha vector section
 * zay m3mlna feel startup.s 3mlna (.section .vectors)
 * kda a7na fe el startup.s 3rfna section gded asmo vectors n3melo azay ba2a fe startup.c
 *//*
    * ana 3amlt kda leh 3l4an a3ml array kolha uninitiazaised f kda hyt7ato fen 
    * hyt7ato fe el bss section f kda ana 3rf awsl l  bss 
    * w ba3d kda azwed el shift ely ana 3ayzo 3l4an awsl el stack top 
    * l awl el stack b any azsed el size bta3 el array 	
	* 256 * 4 = 1024 byte
	*//*
	   * note el array da men no3 unsigned long -> y3ny
       * kol element bya5od fe t5zeno 4bytes 	   
	   */
static uint32_t Stack_top[256];
/*
 * ana hena 3yaz a3ml global array of pointers to functions 
 * leh -> 3l4an lama a3ml ay ISR gded a5ly el poiner da yro7 
 * y4awer 3aleh f kda ana 5leto y4of el ISR w y7oto fe mkano elsa7 
 * fe el vector table section
 * w 3mlt el pointer constant 3l4an m5le4 el pointer da ay 7ad yl3b feh w y8yer mkano 3l4an 
 * kol pointer fe el array by4awer 3ala ISR mo3yen fe el vector table
 */
void (* const g_p_fun_Vectors[])() __attribute__((section(".vectors")))=
{
	/*
	 * casting to pointer to function case array is contain of pointers to functions
	 *to know that isa address not integer 
	 */
(void (*)()) ((uint32_t)Stack_top +sizeof(Stack_top)),
&Reset_Handler       ,      
&NMI_Handler         ,          
&HardFault_Handler          
};

extern uint32_t _E_text  ;
extern uint32_t _S_DATA  ;
extern uint32_t _E_DATA  ;
extern uint32_t _S_BSS   ;
extern uint32_t _E_BSS   ;

extern void main();
void Reset_Handler ()
{ 
    /*
	 *  *((unsigned char*) -> to copy data line by line  
     *//*
	    * copy data from flash to sram in data section 
	    */
	uint32_t DATA_SIZE = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA ;
	unsigned char* P_src =     (unsigned char*)&_E_text ;
	unsigned char* P_dst =     (unsigned char*)&_S_DATA ;
	for(int i = 0 ; i < DATA_SIZE ; i++ )
		{
			*((unsigned char*)P_dst++) = *((unsigned char*)P_src++); 
		}
	/*
	 * initialize the bss section with zeros
	 */
	uint32_t BSS_SIZE = (unsigned char*)&_E_BSS - (unsigned char*)&_S_BSS ;
    P_dst = (unsigned char*)&_S_BSS;
	for(int i = 0 ; i < BSS_SIZE ; i++ )
		{
			*((unsigned char*)P_dst++) = (unsigned char)0; 
		}
	/*
	 * jump to main() to start to execute program and flashing 
	 */
	main();
	
}