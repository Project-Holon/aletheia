/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/000_02004000.s.
 *
 * function: sub_0200575C
 * address:  0x0200575C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Original (12 bytes, leaf, one ABS32 literal):
 *   lsls r1, r0, #2
 *   ldr  r0, [pc, #4]     ; &sub_0200575C_Table
 *   ldr  r0, [r0, r1]
 *   bx   lr
 *   .word <table>
 *
 * A plain pointer-table lookup with no bounds check.  The index is scaled
 * by 4 into a register rather than folded into the load offset, which is
 * what a variable index looks like in Thumb.  The literal is a relocation
 * and is wildcarded, so the verdict is MATCH rather than EXACT.
 */

typedef unsigned int u32;

extern void *sub_0200575C_Table[];

void *sub_0200575C(u32 index)
{
    return sub_0200575C_Table[index];
}
