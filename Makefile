# Збірка ядра системи та її запуск
all: compile run

# Коміпляція вихідний файл
compile:
	nasm -f elf32 ./source/kernel.asm -o ./dist/kasm.o
	gcc -m32 -c -fno-stack-protector ./source/kernel.c -o ./dist/kc.o
	ld -m elf_i386 -T ./source/link.ld -o bareos/boot/kernel.bin ./dist/kasm.o ./dist/kc.o
	grub-mkrescue -o bareos.iso bareos/

# Запуск ядра в емуляторі Qemu
run:
	qemu-system-x86_64 bareos.iso

# Вилучення всіх похідних файлів
clear:
	rm -f dist/*.o
	rm -f bareos/boot/kernel.bin
	rm -f bareos.iso