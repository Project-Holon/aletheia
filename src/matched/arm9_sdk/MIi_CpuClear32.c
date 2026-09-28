/*
 * function: MIi_CpuClear32
 * address:  0x02082A7C
 * packet:   pkt_02082A7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void MIi_CpuClear32(void)
{
    add ip, r1, r2
loc_02082A80:
    cmp r1, ip
    stmltia r1!, {r0}
    blt loc_02082A80
    bx lr
}
