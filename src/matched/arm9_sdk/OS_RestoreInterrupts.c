/*
 * function: OS_RestoreInterrupts
 * address:  0x0208799C
 * packet:   pkt_0208799C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void OS_RestoreInterrupts(void)
{
    mrs	r1, cpsr
    bic	r2, r1, #0x80
    orr	r2, r2, r0
    msr	cpsr_c, r2
    and	r0, r1, #0x80
    bx	lr
}
