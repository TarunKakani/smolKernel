<h1>Smol Kernel</h1>

<h3>How does an x86 machine boot</h3>

<p>
Most registers of the x86 cpu have well defined values after power on.

The instruction pointer (EIP) register holds the memory address for the instruction being executed 
by the processor.

EIP is hardcoded to the value <b>0xFFFFFFF0</b>. Thus the x86 cpu is hardwired to being execution
at the physical address mentioned above.

Thi is the last 16 bytes of the 32-bit address space. This memory address is called
<b>reset vector.</b>

<i>Next part...</i>

Now the chipset's memory map makes sure that 0xFFFFFFF0 is mapped to certain part of the BIOS, not to the RAM. Meanwhile the BIOS copies itself to the RAM for faster access. This is called 
<b>shadowing.</b>

The address 0xFFFFFFF0 will contain just a jump instruction to the address in memory where BIOS has copied itself.
</p>
