/*
 * function: INITi_CpuClear32
 * address:  0x02004A00
 * packet:   pkt_02004A00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void INITi_CpuClear32(void)
{
    add r12, r1, r2
_loop:
    cmp r1, r12
    strlt r0, [r1], #4
    blt _loop
    bx lr
}
