global _start

section .text

_start: 
    %define quadrado(x)     (x*x)
    %define cubo(x)         (x*x*x)
    %define conta_1(x,y)      ((x*2)+y)
    %define conta_2(x,y,z)      (((4+x)*y)/z)
exit:
    mov rax, 60
    mov rdi, 0
    syscall

section .data
    msg db "Oi", 0, 10
