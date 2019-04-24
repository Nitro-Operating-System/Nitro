OBJECTS = kernel/init.c kernel/print.c kernel/intr/panic.c kernel/intr/interrupt.c 
ASSEMBLY = sys/boot.asm sys/intrhandle.asm
BUILT = print.o init.o panic.o interrupt.o
BUILTASM = intrhandle.o boot.o
default: prog
NASMFLAGS = -f elf32
clean: 
	rm $(BUILT) $(BUILTASM) kern
prog: 
	gcc -m32 -Wall -c $(OBJECTS)
	nasm $(NASMFLAGS) sys/boot.asm -o boot.o
	nasm $(NASMFLAGS) sys/intrhandle.asm -o intrhandle.o
	echo "To link"
	ld -m elf_i386 -T sys/link.ld -o kern intrhandle.o interrupt.o boot.o panic.o print.o init.o
	qemu-system-i386 -kernel kern
	
