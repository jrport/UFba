bits 64

section .bss
    num resb 255

section .text
    global _start

_start: 
    xor rax, rax
    mov rsi, num
    mov rdi, 1
    mov rdx, 255
    syscall

    ;dec rax
    mov rdx, rax
    mov rax, 1
    mov rsi, num
    mov rdi, 1
    syscall

    mov rax, 60
    mov rdi, 0
    syscall
