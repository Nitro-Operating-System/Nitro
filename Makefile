OBJECTS = kernel/init.c kernel/print.c kernel/panic.c kernel/interrupt.c kernel/welcome.c
BUILT = print.o init.o panic.o interrupt.o welcome.o
BUILTASM = boot.o
default: prog
NASMFLAGS = -f elf32
GCCFLAGS = -m32 -Wall -c
clean: 
	rm $(BUILT) $(BUILTASM) kern
prog: 
	gcc $(GCCFLAGS) $(OBJECTS)
	nasm $(NASMFLAGS) sys/boot.asm -o boot.o
	ld -m elf_i386 -T sys/link.ld -o kern $(BUILTASM) $(BUILT)
run:
	qemu-system-i386 -kernel kern
