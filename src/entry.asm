
global start

extern kmain
section .text
bits 32
start:
	mov ebp, stack_start
	call kmain
	hlt

section .bss
stack_end:
	resb 4096 * 4
stack_start:
