/*
 * file:     cp_context.c
 * unit:     yes
 * function: CP_SaveContext, CPi_RestoreContext
 * address:  0x020775B8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
asm void CP_SaveContext(void);
asm void CPi_RestoreContext(void);

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
