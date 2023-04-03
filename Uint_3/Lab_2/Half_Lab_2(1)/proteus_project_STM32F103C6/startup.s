/*
 * learn-in-dedpth.com
 * Mastering Embedded System online Diploma
 * Eng.Elsayed Ayman Elsayed Ali Habib
 */
 
/*
 * .word -> word to create variable in assembly code in all 32 bits
 * symbol is just an address like _reset
 */
/*
 * men el cross toolchain by2oly any lw 3ayz a3ml section yzharly 
 * m3 el sections ely heya zay .data w .text w .bss w .vectors 
 * hat3ml kda (.section .vectors)
 */
 
.section .vectors

.word 0x20001000         /*  Stack_Top_Address   */
.word _reset             /*  Reset_Handler       */
.word Vector_handler     /*  NMI_Handler         */    
.word Vector_handler     /*  HardFault_Handler   */     
.word Vector_handler     /*  MemManage_Handler   */     
.word Vector_handler     /*  BusFault_Handler    */
.word Vector_handler     /*  UsageFault_Handler  */    
.word Vector_handler     /*  SVC_Handler         */
.word Vector_handler     /*  DebugMon_Handler    */
.word Vector_handler     /*  PendSV_Handler      */
.word Vector_handler     /*  SysTick_Handler     */
               /*Athor_Handlers*/

/*
 * da bas 3l4an elt2ked bas 
 * lakn a7na 3arfen an el assembly lines kda kda byt7ato fe el text section
 */
.section .text
_reset: 
	bl main
	b .
	
.thumb_func
Vector_handler:
	b _reset