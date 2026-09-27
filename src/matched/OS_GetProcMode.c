/*
 * function: OS_GetProcMode
 * address:  0x020879EC
 * packet:   pkt_020879EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm unsigned int OS_GetProcMode(void)
{
    mrs r0, cpsr
    and r0, r0, #0x1f
    bx lr
}
