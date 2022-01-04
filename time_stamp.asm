;
;   Source code written by Gabriel Correia
;

global getts

section .text
; Returns the CPU timestamp from the RDTSC instruction
getts:
    push rbp
    mov rbp, rsp
    sub rsp, 16
    ; Retrive the current TSC
    rdtsc
    ; 32 - 31
    ; [VALUE - 0]
    shl rdx, 32
    ; OR with RAX = [0 - VALUE] with RDX = [VALUE - 0]
    or rax, rdx

    leave
    ret



