/*
 * file:     gxasm.c
 * unit:     yes
 * function: GX_SendFifo48B, GX_SendFifo64B
 * address:  0x02080C84
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
asm void GX_SendFifo48B(const void *pSrc);
asm void GX_SendFifo64B(const void *pSrc);

/*
 * sdk:      GX_SendFifo48B (libgx.TWL.HYB.a gxasm.o)
 * asm:      gxasm.o is an asm-only object (no compiled subprograms); the body is
 *           a fixed-register ldm/stm block copy into the geometry FIFO.
 *
 * void GX_SendFifo48B(const void *pSrc, void *pDest)
 * hand-written in the original: ldm/stm FIFO burst, one SDK line-table row per instruction
 */
asm void GX_SendFifo48B(const void *pSrc)
{
    ldmia r0!, {r2, r3, r12}
    stmia r1, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1, {r2, r3, r12}
    bx lr
}

/*
 * sdk:      GX_SendFifo64B (libgx.TWL.HYB.a gxasm.o)
 * asm:      gxasm.o is an asm-only object (no compiled subprograms); the body is
 *           a fixed-register ldm/stm block copy into the geometry FIFO.
 *
 * void GX_SendFifo64B(const void *pSrc, void *pDest)
 * hand-written in the original: ldm/stm FIFO burst, one SDK line-table row per instruction
 */
asm void GX_SendFifo64B(const void *pSrc)
{
    stmfd sp!, {r4, r5, r6, r7, r8}
    ldmia r0!, {r2, r3, r4, r5, r6, r7, r8, r12}
    stmia r1, {r2, r3, r4, r5, r6, r7, r8, r12}
    ldmia r0!, {r2, r3, r4, r5, r6, r7, r8, r12}
    stmia r1, {r2, r3, r4, r5, r6, r7, r8, r12}
    ldmfd sp!, {r4, r5, r6, r7, r8}
    bx lr
}
