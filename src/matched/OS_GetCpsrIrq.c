/*
 * function: OS_GetCpsrIrq
 * address:  0x020879E0
 * packet:   pkt_020879E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm unsigned int OS_GetCpsrIrq(void)
{
    mrs r0, cpsr
    and r0, r0, #0x80
    bx lr
}
