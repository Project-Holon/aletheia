/*
 * function: OS_RestoreInterrupts_IrqAndFiq
 * address:  0x020879C8
 * packet:   pkt_020879C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void OS_RestoreInterrupts_IrqAndFiq(void)
{
    mrs	r1, cpsr
    bic	r2, r1, #0xc0
    orr	r2, r2, r0
    msr	cpsr_c, r2
    and	r0, r1, #0xc0
    bx	lr
}
