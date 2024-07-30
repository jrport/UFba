section .data
	pergunta db "Expresse uma altura em metros: ", 0
	fmt db "%f"
	fmt_print db "%f"
	user_input dd 0.0

section .text
global main
extern printf, scanf

main:
	push rbp
	mov rbp, rsp

	mov rdi, pergunta
	call printf

_a:
	mov rdi, fmt_print
	mov rsi, user_input
	call scanf
	
_b:
	mov rdi, fmt_print
	mov rsi, user_input
	call printf

	MOV rdx, 0
	MOV rax, 60
	MOV rdi, 0
	syscall
