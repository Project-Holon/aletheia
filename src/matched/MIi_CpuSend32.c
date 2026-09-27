/*
 * function: MIi_CpuSend32
 * address:  0x02082AA8
 * packet:   pkt_02082AA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void MIi_CpuSend32(void)
{
    add ip, r0, r2
loc_02082AAC:
    cmp r0, ip
    ldmltia r0!, {r2}
    strlt r2, [r1]
    blt loc_02082AAC
    bx lr
}
