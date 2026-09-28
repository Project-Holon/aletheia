/*
 * function: MI_Copy48B
 * address:  0x02082B7C
 * packet:   pkt_02082B7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libmi mi_memory.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  An asm
 * function in the vendor source: four three-register ldm/stm pairs.
 * void MI_Copy48B(const void *pSrc, void *pDest).
 */

asm void MI_Copy48B(void)
{
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    bx lr
}
