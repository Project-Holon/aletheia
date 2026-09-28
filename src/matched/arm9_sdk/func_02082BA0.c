/*
 * function: func_02082BA0
 * address:  0x02082BA0
 * packet:   pkt_02082BA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_Copy64B  0x02082BA0  arm
 */

asm void func_02082BA0(void)
{
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0!, {r2, r3, ip}
    stmia r1!, {r2, r3, ip}
    ldmia r0, {r0, r2, r3, ip}
    stmia r1!, {r0, r2, r3, ip}
    bx lr
}
