/*
 * function: func_02073BE0
 * address:  0x02073BE0
 * packet:   pkt_020737C0
 * status:   EXACT
 * isa:      arm
 * compiler: ../2.0/sp2
 * symbols:
 *   func_02073BF0  0x02073BF0  arm
 *
 * The timer callback func_020738C0 hands to func_02089540 (the pool word at
 * 0x02073A58): steps the sequence object with argument 1.  An unlabelled leaf
 * (`ldr ip,[pc,#4]; mov r1,#1; bx ip` plus the pool word) that disasm.py
 * prints as a .word run after pool_02073BDC.
 */
typedef unsigned int u32;

extern void func_02073BF0(void *o, u32 arg);

void func_02073BE0(void *o)
{
    func_02073BF0(o, 1);
}
