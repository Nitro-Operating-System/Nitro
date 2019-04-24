OBJECTS = kernel/init.c kernel/print.c kernel/intr/panic.c kernel/intr/interrupt.c 
ASSEMBLY = sys/boot.asm sys/intrhandle.asm
BUILT = print.o init.o panic.o intrhandle.o
BUILTASM = intrhandle.o boot.o
default: program
NASMFLAGS = -f elf32
clean: program
	rm $(BUILT) boot.o kern kernel.a interrupt.o
program: kern
	qemu-system-i386 -kernel kern
	rm $(BUILT) boot.o kern kernel.a
kern: sys/link.ld asm.o kernel.a
	ld -m elf_i386 -T sys/link.ld -o kern asm.o kernel.a
$(BUILTASM): $(ASSEMBLY)
	nasm $(NASMFLAGS) boot.asm -o boot.o
	nasm $(NASMFLAGS) intrhandle.asm -o intrhandle.o
kernel.a: $(BUILT)
	ar cr kernel.a $(BUILT)
asm.o:
	ld -o asm.o $(BUILTASM) -lc
$(BUILT): $(OBJECTS)
	gcc -m32 -Wall -c $(OBJECTS)

	
