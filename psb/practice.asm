global _start

section .data
  msg1 db "Sexo?", 10
  msg2 db "Cu", 10
  count db 1

section .text
  _start:
    mov byte[count], byte 1
  l1:
    inc byte[count]
    mov rax, 1
    mov rdi, 1
    mov rdx, 6
    mov rsi, msg1
    syscall
    cmp byte[count], 10
    jne l1
  done:
    mov rax, 60
    mov rdi, 0
    syscall
