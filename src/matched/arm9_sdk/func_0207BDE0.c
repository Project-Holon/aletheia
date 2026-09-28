/*
 * function: func_0207BDE0
 * address:  0x0207BDE0
 * packet:   pkt_0207BDE0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MTX_Copy44To43_ (fx_mtx44.o)
 *
 * asm:      fixed-register ldm/stm block copy (ldmia r0!/stmia r1!, {r2, r3, r12}) has no C spelling
 *
 * symbols:
 *   (none)
 */

typedef long fx32;

typedef union {
    fx32 m[4][4];
    fx32 a[16];
} MtxFx44;

typedef union {
    fx32 m[4][3];
    fx32 a[12];
} MtxFx43;

asm void func_0207BDE0(MtxFx44 *pSrc, MtxFx43 *pDst)
{
    ldmia r0!, {r2, r3, r12}
    add r0, r0, #4
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    add r0, r0, #4
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    add r0, r0, #4
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    add r0, r0, #4
    stmia r1!, {r2, r3, r12}
    bx lr
}
