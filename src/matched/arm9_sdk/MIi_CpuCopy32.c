/*
 * function: MIi_CpuCopy32
 * address:  0x02082A90
 * packet:   pkt_02082A90
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void MIi_CpuCopy32(void)
{
    add ip, r1, r2
loc_02082A94:
    cmp r1, ip
    ldmltia r0!, {r2}
    stmltia r1!, {r2}
    blt loc_02082A94
    bx lr
}
