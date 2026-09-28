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
 * symbols:
 *   MTX_Copy44To43_  0x0207BDE0  arm
 *
 * TwlSDK libfx fx_mtx44.o. Hand-written assembly (DWARF has no locals).
 * Copies the upper 4x3 of a 4x4 matrix into a 4x3 matrix.
 */

asm void func_0207BDE0(void)
{
    ldmia r0!, {r2-r3, r12}
    add   r0, r0, #4
    stmia r1!, {r2-r3, r12}

    ldmia r0!, {r2-r3, r12}
    add   r0, r0, #4
    stmia r1!, {r2-r3, r12}

    ldmia r0!, {r2-r3, r12}
    add   r0, r0, #4
    stmia r1!, {r2-r3, r12}

    ldmia r0!, {r2-r3, r12}
    add   r0, r0, #4
    stmia r1!, {r2-r3, r12}

    bx    lr
}
