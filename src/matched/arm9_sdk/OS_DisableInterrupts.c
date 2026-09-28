/*
 * function: OS_DisableInterrupts
 * address:  0x02087988
 * packet:   pkt_02087988
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void OS_DisableInterrupts(void)
{
    mrs	r0, cpsr
    orr	r1, r0, #0x80
    msr	cpsr_c, r1
    and	r0, r0, #0x80
    bx	lr
}
