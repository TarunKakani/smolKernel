<h1>Smol Kernel</h1>

<h3>How does an x86 machine boot?</h3>

<p>
Most registers of the x86 cpu have well defined values after power on.

The instruction pointer (EIP) register holds the memory address for the instruction being executed 
by the processor.

EIP is hardcoded to the value <b>0xFFFFFFF0</b>. Thus the x86 cpu is hardwired to being execution
at the physical address mentioned above.

Thi is the last 16 bytes of the 32-bit address space. This memory address is called
<b>reset vector.</b>

<i>Next part...</i>

<h4>Shadowing</h4>
Now the chipset's memory map makes sure that 0xFFFFFFF0 is mapped to certain part of the BIOS, not to the RAM. Meanwhile the BIOS copies itself to the RAM for faster access. This is called 
<b>shadowing.</b>

The address 0xFFFFFFF0 will contain just a jump instruction to the address in memory where BIOS has
copied itself.

Thus the BIOS starts its code execution. The BIOS searches for a bootable device in the boot menu
with the configured boot device order.

<b>It checks for a certain magic number to determine if the device is bootable or not. Whether
bytes 511 and 512 of first sector are 0xAA55</b>

<h4>Bootloader</h4>
Once the BIOS has found a bootable device it copies the contents of the device's first sector into 
RAM starting from physical address 0x7c00; and then jumps into the address and executes the code 
that just loaded.<b>This code is called the bootloader</b>

The bootloader then loads the kernel at the physical address 0x100000. 
<b>The address 0x100000 is used as the start address for all big kernels on x86 machines.</b>

All the x86 processors begin in a simplistic <b>16-bit mode called real mode.</b>. 
<b>The grub bootloader makes the switch to 32 bit protected mode by settting the lowest big of CR0 
register to 1.</b>

Thus the kernel loads in 32-bit protected mode...

<i>Note: in case of linux kernel, GRUB detects linux boot protocol and loads linux kernel in real 
mode. Linux kernel makes the switch itselt to protected mode.</i>
</p>
