/*
 * function: MTX_RotY33_
 * address:  0x0207AF1C
 * packet:   pkt_0207AF1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

/* hand-written in the original: fx_mtx33.o (libfx) has one .debug_line row per instruction for MTX_RotY33_ (lines 172-184, 186), mov/lsl of 0x1000 on two lines, no DW_TAG_variable; the C ScaleApply33 beside it interleaves lines */
asm void MTX_RotY33_(void)
{
    str r2, [r0]
    str r2, [r0, #0x20]
    mov r3, #0
    str r3, [r0, #4]
    str r3, [r0, #0xc]
    str r3, [r0, #0x14]
    str r3, [r0, #0x1c]
    neg r2, r1
    mov r3, #1
    lsl r3, r3, #12
    str r1, [r0, #0x18]
    str r2, [r0, #8]
    str r3, [r0, #0x10]
    bx lr
}
