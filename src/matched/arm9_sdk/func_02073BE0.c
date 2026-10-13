/*
 * function: NNSi_SndStrmTimerCallback
 * address:  0x02073BE0
 * packet:   pkt_020737C0
 * status:   EXACT
 * isa:      arm
 * compiler: ../2.0/sp2
 * symbols:
 *   NNSi_SndStrmUpdate  0x02073BF0  arm
 *
 * The timer callback NNS_SndStrmSetup hands to func_02089540 (the pool word at
 * 0x02073A58): steps the sequence object with argument 1.  An unlabelled leaf
 * (`ldr ip,[pc,#4]; mov r1,#1; bx ip` plus the pool word) that disasm.py
 * prints as a .word run after pool_02073BDC.
 */
typedef unsigned int u32;

extern void NNSi_SndStrmUpdate(void *o, u32 arg);

void NNSi_SndStrmTimerCallback(void *o)
{
    NNSi_SndStrmUpdate(o, 1);
}
