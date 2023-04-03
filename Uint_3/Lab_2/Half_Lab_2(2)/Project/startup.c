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
void MemManage_Handler (void)__attribute__((weak,alias("Default_Handler")));     
void BusFault_Handler (void)__attribute__((weak,alias("Default_Handler")));  
void UsageFault_Handler (void)__attribute__((weak,alias("Default_Handler")));    
void SVC_Handler (void)__attribute__((weak,alias("Default_Handler"))); 
void DebugMon_Handler (void)__attribute__((weak,alias("Default_Handler")));    
void PendSV_Handler (void)__attribute__((weak,alias("Default_Handler")));  
void SysTick_Handler (void)__attribute__((weak,alias("Default_Handler")));

/*
 * ana azay a3rf an el array de m4 data section 
 * w a3rfo en de asmha vector section
 * zay m3mlna feel startup.s 3mlna (.section .vectors)
 * kda a7na fe el startup.s 3rfna section gded asmo vectors n3melo azay ba2a fe startup.c
 */
extern uint32_t _stack_top ; 
uint32_t vectors[] __attribute__((section(".vectors")))=
{
(uint32_t) &_stack_top          ,/* casting to uint32_t to know that isa address not integer */
(uint32_t) &Reset_Handler       ,      
(uint32_t) &NMI_Handler         ,          
(uint32_t) &HardFault_Handler   ,        
(uint32_t) &MemManage_Handler   ,       
(uint32_t) &BusFault_Handler    , 
(uint32_t) &UsageFault_Handler  ,    
(uint32_t) &SVC_Handler         ,
(uint32_t) &DebugMon_Handler    ,
(uint32_t) &PendSV_Handler      ,
(uint32_t) &SysTick_Handler
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