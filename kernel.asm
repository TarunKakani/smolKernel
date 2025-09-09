;;kernel.asm

bits 32		;nasm directive - 32 bit
section .text
        ;multiboot spec header
        align 4
        dd 0x1BADB002     ;magic field number
        dd 0x00           ;flags field will be set to zero
        dd - (0x1BADB002 + 0x00)    ;this is the checksum. m + f + c should be zero

global start
extern kmain	;kmain is defined in the c file

start:
	cli	;blocks interrupts/ short for clear interrupt
	mov esp, stack_space	;set stack pointer
	call kmain
	hlt

section .bss
resb 8192	;8KB for stack
stack_space:
