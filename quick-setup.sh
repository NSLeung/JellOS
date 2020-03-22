#!/bin/sh

$HOME/opt/cross/bin/$TARGET-gcc -c kernel-hello.c -o kernel-hello.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
$HOME/opt/cross/bin/$TARGET-gcc -c terminal.c -o terminal.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
$HOME/opt/cross/bin/$TARGET-gcc -c test_terminal.c -o test_terminal.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

$HOME/opt/cross/bin/$TARGET-gcc -T linker.ld -o JellOS.bin -ffreestanding -O2 -nostdlib boot.o kernel-hello.o terminal.o test_terminal.o -lgcc
cp JellOS.bin ./isodir/boot/JellOS.bin
grub-mkrescue -o JellOS.iso isodir