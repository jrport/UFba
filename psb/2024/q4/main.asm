extern printf, scanf, media_aritimetica, media_geometrica, media_harmonica
global  main

section .data
    pergunta db "Vamos calcular 3 médias.", 10, "Para isso serão necessários 3 números!", 10, "Insira-os a seguir, na mesma linha, separados por espaço, e.g. '1 2 3'.", 10, 0
    resposta_1 db "Média aritmética: %.2f", 10, 0
    resposta_2 db "Média geometrica: %.2f", 10, 0
    resposta_3 db "Média harmonica: %.2f", 10, 0
    fmtIn db "%d %d %d", 0

section .bss
    inteiro_1 resb 4
    inteiro_2 resb 4
    inteiro_3 resb 4

section .text
main:
    ; limpa e alinha o stack
    push rbp
    mov rbp, rsp
    sub rsp, 32

    ; prompt e input dos 3 inteiros
    xor rax, rax
    mov rdi, pergunta
    call printf

    xor rax, rax

    mov rdi, fmtIn
    mov rsi, inteiro_1
    mov rdx, inteiro_2
    mov rcx, inteiro_3
    call scanf

    mov edi, [inteiro_1]
    mov esi, [inteiro_2]
    mov edx, [inteiro_3]
    call media_aritimetica 

    mov rax, 1
    mov rdi, resposta_1
    call printf

    xor rax, rax

    mov edi, [inteiro_1]
    mov esi, [inteiro_2]
    mov edx, [inteiro_3]

    call media_geometrica

    mov rax, 1
    mov rdi, resposta_2
    call printf

    xor rax, rax

    mov edi, [inteiro_1]
    mov esi, [inteiro_2]
    mov edx, [inteiro_3]

    call media_harmonica

    mov rax, 1
    mov rdi, resposta_3
    call printf

exit:
    mov rax, 0
    leave
    ret
