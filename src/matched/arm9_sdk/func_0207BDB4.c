/*
 * function: MTX_Identity44_
 * address:  0x0207BDB4
 * packet:   pkt_0207BDB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MTX_Identity44_ (fx_mtx44.o)
 *
 * asm:      fixed-register stm block (stmia r0!, {r1, r2, r3} runs) has no C spelling
 *
 * symbols:
 *   (none)
 */

typedef long fx32;

typedef union {
    fx32 m[4][4];
    fx32 a[16];
} MtxFx44;

asm void MTX_Identity44_(MtxFx44 *pDst)
{
    mov r2, #0x1000
    mov r3, #0
    stmia r0!, {r2, r3}
    mov r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2}
    bx lr
}
