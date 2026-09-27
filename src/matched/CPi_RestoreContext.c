/*
 * function: CPi_RestoreContext
 * address:  0x020775F8
 * packet:   pkt_020775F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libcp cp_context.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  An asm
 * function in the vendor source.  void CPi_RestoreContext(CPContext *context).
 */

asm void CPi_RestoreContext(void)
{
    stmfd sp!, {r4}
    ldr r1, =0x04000290
    ldmia r0, {r2, r3, r4, r12}
    stmia r1, {r2, r3, r4, r12}
    ldrh r2, [r0, #0x18]
    ldrh r3, [r0, #0x1a]
    strh r2, [r1, #-0x10]
    strh r3, [r1, #0x20]
    add r0, r0, #0x10
    add r1, r1, #0x28
    ldmia r0, {r2, r3}
    stmia r1, {r2, r3}
    ldmfd sp!, {r4}
    bx lr
}
