OBJECTS = kernel/init.c kernel/print.c kernel/intr/panic.c kernel/intr/interrupt.c 
ASSEMBLY = sys/boot.asm sys/intrhandle.asm
BUILT = print.o init.o panic.o intrhandle.o
default: program
NASMFLAGS = -f elf32
clean:
	rm $(BUILT) boot.o kern kernel.a interrupt.o
program: kern
	qemu-system-i386 -kernel kern
	rm $(BUILT) boot.o kern kernel.a
kern: sys/link.ld boot.o kernel.a
	ld -m elf_i386 -T sys/link.ld -o kern boot.o kernel.a
boot.o: $(ASSEMBLY)
	nasm $(NASMFLAGS) $(ASSEMBLY) -o boot.o
kernel.a: $(BUILT)
	ar cr kernel.a $(BUILT)
$(BUILT): $(OBJECTS)
	gcc -m32 -Wall -c $(OBJECTS)

	
