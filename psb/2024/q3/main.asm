bits 64

section .data
    name_prompt db "Insira seu nome: "
    name_prompt_len equ $ - name_prompt
    par db "É par!", 10
    par_len equ $ - par
    impar db "É impar!", 10
    impar_len equ $ - impar

section .bss
    buffer resb 255

section .text
    global  _start

_start:
    ; prompt e leitura do nome
    mov rax, 1 
    mov rdi, 1
    mov rsi, name_prompt
    mov rdx, name_prompt_len
    syscall

    mov rax, 0
    mov rdi, 1
    mov rsi, buffer
    mov rdx, 255
    syscall

    mov rcx, 0

.loop:
    ; acha o comprimento do nome
    cmp byte [buffer + rcx], 0
    je .end_loop

    inc rcx
    jmp .loop

.end_loop:
    dec rcx

    ; checa divisao por 1
    cmp rcx, 0
    je .impar_message
    
    xor ah, ah
    xor al, al
    xor bx, bx

    mov ax, cx
    mov bx, 2      
    xor dx, dx
    div bx          
    
    cmp dx, 0
    je .par_message
    jmp .impar_message

.par_message: 
    mov rsi, par
    mov rdx, par_len
    jmp .print

.impar_message:
    mov rsi, impar
    mov rdx, impar_len
    jmp .print

.print:
    mov rdi, 1
    mov rax, 1 
    syscall 

    jmp .exit

.exit: 
    mov rax, 60
    xor rdi, rdi
    syscall
