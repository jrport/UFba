; ATIVIDADE PRATICA 2 - QUESTÂO 1 
; JOÃO ROBERTO DA SILVA PORTO - 222217111
global main

extern scanf
extern printf
extern stdout
extern fflush

section .data
  prompt_for_name db "Insira seu nome: ", 0
  prompt_for_letter db "Insira a letra a ser buscada: ", 0
  found db 10, "A letra foi encontrada", 10, 0
  not_found db 10, "A letra não foi encontrada",10, 0
  name_format db "%s", 0
  letter_format db "%c", 0
  first_out db "Primeira Letra: ", 0
  last_out db 10, "Ultima Letra: ", 0
  check db 1

section .bss 
  name resb 256
  letter resb 1

section .text
  main:
    push rbp
    mov rbp, rsp
  
    mov rdi, prompt_for_name
    call printf
    mov rdi, [stdout]
    call fflush

    mov rdi, name_format
    mov rsi, name
    call scanf

    mov rdi, prompt_for_letter
    call printf
    mov rdi, [stdout]
    call fflush

    mov rdi, name_format
    mov rsi, letter
    call scanf
    
    mov rdi, first_out
    call printf
    mov rdi, [stdout]
    call fflush

    ;printing first letter using syscall (i just have to 
    ;print the adress value directly)
    mov rax, 1
    mov rsi, name
    mov rdi, 1
    mov rdx, 1
    syscall

    mov rdi, last_out
    call printf
    mov rdi, [stdout]
    call fflush

    mov rax, name
    mov rbx, [letter]
  .get_last:
    cmp rax, rbx
    je .change_check
    inc rax
    cmp byte[rax], 0x0
    jne .get_last

  .exit:
    dec rax
    mov rsi, rax
    mov rdi, 1
    mov rax, 1
    mov rdx, 1
    syscall
     
    mov rax, 1
    mov rbx, [check]
    cmp rbx, rax
    jl .present
    jmp .missing 

  .quit:
    mov     rax, 60
    xor     rdi, rdi
    syscall

  .change_check:
    inc rax
    mov byte[check], 2
    jmp .get_last

  .present:
    mov rdi, found
    call printf
    mov rdi, [stdout]
    call fflush
    jmp .quit

  .missing:
    mov rdi, not_found
    call printf

    mov rdi, [stdout]
    call fflush
    jmp .quit
