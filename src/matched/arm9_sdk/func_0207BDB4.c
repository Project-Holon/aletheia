/*
 * function: func_0207BDB4
 * address:  0x0207BDB4
 * packet:   pkt_0207BDB4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MTX_Identity44_  0x0207BDB4  arm
 *
 * TwlSDK libfx fx_mtx44.o. Hand-written assembly (DWARF has no locals).
 * Writes the 4x4 identity matrix (FX32_ONE on the diagonal).
 */

asm void func_0207BDB4(void)
{
    mov   r2, #4096
    mov   r3, #0
    stmia r0!, {r2, r3}
    mov   r1, #0
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2, r3}
    stmia r0!, {r1, r3}
    stmia r0!, {r1, r2}

    bx    lr
}
