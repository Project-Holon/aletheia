/*
 * function: CP_SaveContext
 * address:  0x020775B8
 * packet:   pkt_020775B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libcp cp_context.o (.comment stamp 4.0.0.1024, dsi/1.1p1).  An asm
 * function in the vendor source.  void CP_SaveContext(CPContext *context):
 * copies the divider operands (0x04000290), the sqrt parameter (0x040002B8)
 * and the two control halfwords.
 */

asm void CP_SaveContext(void)
{
    ldr r1, =0x04000290
    stmfd sp!, {r4}
    ldmia r1, {r2, r3, r4, r12}
    stmia r0!, {r2, r3, r4, r12}
    ldrh r12, [r1, #-0x10]
    add r1, r1, #0x28
    ldmia r1, {r2, r3}
    stmia r0!, {r2, r3}
    and r12, r12, #3
    ldrh r2, [r1, #-8]
    strh r12, [r0]
    and r2, r2, #1
    strh r2, [r0, #2]
    ldmfd sp!, {r4}
    bx lr
}
