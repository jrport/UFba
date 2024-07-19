bits 64

section .data
    msg db "Expresse sua idade em, ", 10
    msg_len equ $ - msg
    anos_msg db "Anos: ", 0
    anos_len equ $ - anos_msg
    meses_msg db "Meses: ", 0
    meses_len equ $ - meses_msg
    dias_msg db "Dias: ", 0
    dias_len equ $ - dias_msg

section .bss
    idade_total resb 255
    anos resb 255
    meses resb 255
    dias resb 255

section .text
    global _start

_start: 
    ; prompt da idade e inputs
    mov rax, 1
    mov rdx, msg_len
    mov rsi, msg
    mov rdi, 1
    syscall 

    mov rax, 1
    mov rdx, anos_len
    mov rsi, anos_msg
    mov rdi, 1
    syscall 

    xor rax, rax
    mov rdx, 255
    mov rsi, anos
    mov rdi, 1
    syscall

    mov rax, 1
    mov rdx, meses_len
    mov rsi, meses_msg
    mov rdi, 1
    syscall 

    xor rax, rax
    mov rdx, 255
    mov rsi, meses
    mov rdi, 1
    syscall

    mov rax, 1
    mov rdx, dias_len
    mov rsi, dias_msg
    mov rdi, 1
    syscall 

    xor rax, rax
    mov rdx, 255
    mov rsi, dias
    mov rdi, 1
    syscall

    ; anos
    xor rax, rax
    mov rbx, 365
    mov rax, [anos]
    .anos:
    sub rax, '0'
    mul rbx
    mov r9, rax
    
    ; meses
    xor rax, rax
    mov rbx, 30
    mov rax, [meses]
    sub rax, '0'
    mul rbx
    mov r10, rax

    xor rax, rax
    mov rax, r9
    add rax, r10
    mov rbx, [dias]
    sub rbx, '0'
    add rax, rbx

    .res:
    mov r11, rax

    jmp .exit

.exit:
    mov rax, 60
    mov rdi, 0
    syscall
