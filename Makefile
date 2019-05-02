OBJECTS = kernel/init.c kernel/print.c kernel/panic.c kernel/interrupt.c 
ASSEMBLY = sys/boot.asm sys/irh.asm 
BUILT = print.o init.o panic.o interrupt.o
BUILTASM = boot.o irh.o
default: prog
NASMFLAGS = -f elf32
GCCFLAGS = -m32 -Wall -c
clean: 
	rm $(BUILT) $(BUILTASM) kern
prog: 
	gcc $(GCCFLAGS) $(OBJECTS)
	nasm $(NASMFLAGS) sys/irh.asm -o irh.o
	nasm $(NASMFLAGS) sys/boot.asm -o boot.o
	ld -m elf_i386 -T sys/link.ld -o kern $(BUILTASM) $(BUILT)
	qemu-system-i386 -kernel kern
	
