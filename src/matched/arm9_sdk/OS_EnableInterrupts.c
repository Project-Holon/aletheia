/*
 * function: OS_EnableInterrupts
 * address:  0x02087974
 * packet:   pkt_02087974
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void OS_EnableInterrupts(void)
{
    mrs	r0, cpsr
    bic	r1, r0, #0x80
    msr	cpsr_c, r1
    and	r0, r0, #0x80
    bx	lr
}
