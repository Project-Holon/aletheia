/*
 * function: func_0207B5C0
 * address:  0x0207B5C0
 * packet:   pkt_0207B5C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MTX_Copy43To44_ (libfx.TWL.HYB.a fx_mtx43.o)
 * asm:      fixed-register ldm/stm block copy with writeback (ldmia r0!, stmia r1!); no C spelling.
 *
 * symbols:
 *   (none)
 */

asm void func_0207B5C0(void)
{
    stmfd sp!, {r4}
    mov r12, #0
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, r12}
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, r12}
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, r12}
    mov r12, #0x1000
    ldmia r0!, {r2, r3, r4}
    stmia r1!, {r2, r3, r4, r12}
    ldmfd sp!, {r4}
    bx lr
}
