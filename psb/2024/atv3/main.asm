extern scanf, printf
global main

section .data
    prompt db "Digite quatro alturas em metros (como x.xx) separadas por espaço", 10, 0
    fmtin db "%lf %lf %lf %lf", 0        
    fmtout db "A média é: %lf", 10, 0 
    float1 dq 0.0            
    float2 dq 0.0            
    float3 dq 0.0            
    float4 dq 0.0            
    divisor dq 4.0

section .text
main:
    ; limpa e alinha o stack
    sub rsp, 0x28
    mov rax, rsp
    and rax, 0xFFFFFFF0
    mov rsp, rax

    ; prompt e input dos floats
    mov rdi, prompt              
    call printf                

    mov rdi, fmtin          
    mov rsi, float1         
    mov rdx, float2         
    mov rcx, float3         
    mov r8, float4         
    call scanf              

    ; passa os floats pros xmm 
    ; pra usar as op's sse (operações simd)
    movsd xmm0, [float1]   
    movsd xmm1, [float2]   
    movsd xmm2, [float3]   
    movsd xmm3, [float4]   


    ; soma os floats
    addsd xmm0, xmm1      
    addsd xmm0, xmm2      
    addsd xmm0, xmm3      

    ; carrega o divisor e divide
    movsd xmm1, [divisor]
    divsd xmm0, xmm1

    ; printa
    mov rdi, fmtout      
    call printf          

    xor rdi, rdi        
    mov rax, 60
    syscall

