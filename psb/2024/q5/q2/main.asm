global _start

section .text

%macro strlen_par_impar 1

    %define my_string %1
    %strlen char_qtd my_string
    %if (char_qtd % 2) == 0 
        mov rsi, par
        mov rdx, par_len
    %else
        mov rsi, impar
        mov rdx, impar_len
    %endif

%endm

_start: 
    mov rax, 1 

    %define input "minha_string"
    strlen_par_impar input

    syscall

    mov rax, 60
    mov rdi, 0
    syscall

section .data
    msg db "Insira uma string", 10, 0
    msg_len equ $ - msg
    par db "Par", 10, 0
    par_len equ $ - par
    impar db "Impar", 10, 0
    impar_len equ $ - impar

section .bss
    buffer resb 254
