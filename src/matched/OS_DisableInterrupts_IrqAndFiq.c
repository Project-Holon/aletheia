/*
 * function: OS_DisableInterrupts_IrqAndFiq
 * address:  0x020879B4
 * packet:   pkt_020879B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void OS_DisableInterrupts_IrqAndFiq(void)
{
    mrs	r0, cpsr
    orr	r1, r0, #0xc0
    msr	cpsr_c, r1
    and	r0, r0, #0xc0
    bx	lr
}
