/*
 * function: MTX_RotY43_
 * address:  0x0207B640
 * packet:   pkt_0207B640
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * sdk:      MTX_RotY43_ (libfx.TWL.HYB.a fx_mtx43.o)
 * asm:      fixed-register stm with writeback (stmia r0!, {r1, r2, r3}); no C spelling.
 *
 * symbols:
 *   (none)
 */

asm void MTX_RotY43_(void)
{
    str r1, [r0, #0x18]
    mov r3, #0
    stmia r0!, {r2, r3}
    neg r1, r1
    stmia r0!, {r1, r3}
    mov r1, #1
    lsl r1, r1, #0xc
    stmia r0!, {r1, r3}
    add r0, #4
    mov r1, #0
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r3}
    bx lr
}
