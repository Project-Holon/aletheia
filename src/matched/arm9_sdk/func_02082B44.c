/*
 * function: MI_Copy32B
 * address:  0x02082B44
 * packet:   pkt_02082B44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MI_Copy32B (libmi.TWL.HYB.a mi_memory.o)
 * asm:      fixed-register ldm/stm block copy (ldm r0!,{r2,r3,r12}) has no C spelling.
 *
 * void MI_Copy32B(void *pSrc, void *pDest).
 */

asm void MI_Copy32B(void)
{
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3}
    stmia r1!, {r2, r3}
    bx lr
}
