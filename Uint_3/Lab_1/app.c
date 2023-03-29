/*
 * learn-in-dedpth.com
 * Mastering Embedded System online Diploma
 * Eng.Elsayed Ayman Elsayed Ali Habib
 */
 
 /*
  * arm-none-eabi-gcc.exe ->
  * -s -> compile after per compile = assemply file and stop
  * -c -> compile without linkeing = object file and stop
  * -mcpu= -> determiend the core that code execte (proce)
  * -I -> include headers 
  * . after -I -> to include header files in the same folder that contain the app
  * -o0 or -o1 or -o2 or -03 -> optomization level
  * -o -> to get object file from .c file
  * arm-none-eabi-ar.exe rcs lib_uart.a uart.o (Example -> uart)
  * /*
     * to see sections in termina 
     * arm-none-eabi-objdump.exe -h app.o
     */
 #include "uart.h"
 
 unsigned char string_buffer[100] = "learn-in-dedpth:<Elsayed>";
 unsigned char const string_buffer1[100] = "learn-in-dedpth:<Elsayed>";
 void main (void)
 {
	 Uart_Send_String(string_buffer);
 }
 