run:
	rm main.o media.o main
	nasm -f elf64 main.asm
	gcc -c media.c -o media.o
	gcc -o main main.o media.o -no-pie -lm
	./main

primer: 
	nasm -f elf64 main.asm
	gcc -c media.c -o media.o 
	gcc -o main main.o media.o -no-pie -lm
	./main
