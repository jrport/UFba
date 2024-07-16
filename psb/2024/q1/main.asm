bits 64

global  _start

section .text
    exit: 
        mov       rax, 60
        xor       rdi, rdi
        syscall

    achou_flag:
        inc rcx
        mov r10, 1
        jmp loop

    achou: 
        mov rax, 1
        mov rdi, 1
        mov rsi, positivo
        mov rdx, positivo_len
        syscall

        jmp exit

    nao_achou:
        mov rax, 1
        mov rdi, 1
        mov rsi, negativo
        mov rdx, negativo_len
        syscall
        
        jmp exit

    _start:    
        ; prompt da letra
        mov      rax, 1
        mov      rdi, 1
        mov      rsi, pergunta_letra
        mov     rdx, pergunta_letra_len
        syscall

        ; input da letra
        mov      rax, 0
        mov      rdi, 1
        mov      rsi, letra_buffer
        mov     rdx, 2
        syscall

        ; prompt da nome
        mov      rax, 1
        mov      rdi, 1
        mov      rsi, pergunta_nome
        mov     rdx, pergunta_nome_len
        syscall

        ; input do nome
        mov      rax, 0
        mov      rdi, 1
        mov      rsi, name_buffer
        mov     rdx, 255
        syscall

        ; prompt do primeiro digito
        mov rax, 1
        mov rdi, 1
        mov rsi, primeira_letra
        mov rdx, primeira_letra_len
        syscall

        ; imprime primeiro digito
        mov rax, 1
        mov rdi, 1
        mov rsi, name_buffer
        mov rdx, 1
        syscall

        ; nossa flag pra acompanhar a letra
        mov r10, 0

        ; loop para:
        ; 1) pega comprimento da string pra imprimir ultimo digito
        ; 2) checar se tem um certo caractere
        mov rcx, 0
    loop:
        mov rbx, name_buffer
        add rbx, rcx
        cmp bl, byte [letra_buffer]
        je achou_flag
        cmp byte[rbx], 10
        je end
        inc rcx
        jmp loop

    end:    
        mov r9, rcx

        ;prompt do ultimo digito
        mov rax, 1
        mov rdi, 1
        mov rsi, ultima_letra
        mov rdx, ultima_letra_len
        syscall

        ; calcula endereco do buffer com offset
        dec r9
        mov rbx, name_buffer
        add rbx, r9

        ; imprime ultimo digito
        mov rax, 1
        mov rdi, 1
        mov rsi, rbx
        mov rdx, 2
        syscall

         ;imprime se achou ou não o digito
        cmp r10, 0
        je nao_achou
        jmp achou
        ;jmp exit

section   .data
    pergunta_nome:    db    "Insira um nome: ", 0
    pergunta_nome_len: equ $ - pergunta_nome
    primeira_letra: db "Primeira letra: "
    primeira_letra_len: equ $ - primeira_letra
    ultima_letra: db 10, "Ultima letra: "
    ultima_letra_len: equ $ - ultima_letra
    pergunta_letra: db "Letra alvo: ", 0
    pergunta_letra_len: equ $ - pergunta_letra
    positivo: db "Achou a letra!", 0
    positivo_len: equ $ - positivo
    negativo: db "Não encontramos a letra!", 0
    negativo_len: equ $ - negativo

section    .bss
    name_buffer resb 255
    letra_buffer resb 2 
