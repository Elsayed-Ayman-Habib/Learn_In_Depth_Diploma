#@ Eng.Elsayed Ayman Elsayed Ali Habib : (Mastering Embedded System online Diploma)
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -gdwarf-2 -g
# el dot m3naha el path ely ana w2ef 3ndo ya3ny lw el make file bta3y da ana 3ayz a5leh 
# y3ml make l file tany m4 m3ah fe nafs el folder 5las haktb  el path bta3 el file mkan el dot
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As= $(wildcard *.s)
AsOBJ= $(As:.s=.o)
MAP=-Map=output.map
LINK=linker_script
Project_Name= learn-in-depth-tiva

all: $(Project_Name).bin
	@echo "Build if done"

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Project_Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld -T $(LINK).ld $(MAP) $(LIBS) $(OBJ) $(AsOBJ) -o $@
	cp $(Project_Name).elf $(Project_Name).axf 
	
$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean_all:
	rm *.o *.elf *.bin *.map

clean:
	rm *.elf *.bin *.map