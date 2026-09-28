/*
 * function: func_02082B0C
 * address:  0x02082B0C
 * packet:   pkt_02082B0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   CCERR
 *
 * symbols:
 *   MIi_CpuCopyFast  0x02082B0C  arm
 */

asm void func_02082B0C(void)
{
    push {r4, r5, r6, r7, r8, r9, sl}
    add sl, r1, r2
    lsr ip, r2, #5
    add ip, r1, ip, lsl #5
loc_02082B1C:
    cmp r1, ip
    ldmltia r0!, {r2, r3, r4, r5, r6, r7, r8, r9}
    stmltia r1!, {r2, r3, r4, r5, r6, r7, r8, r9}
    blt loc_02082B1C
loc_02082B2C:
    cmp r1, sl
    ldmltia r0!, {r2}
    stmltia r1!, {r2}
    blt loc_02082B2C
    pop {r4, r5, r6, r7, r8, r9, sl}
    bx lr
}
