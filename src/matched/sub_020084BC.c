/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.
 *
 * function: sub_020084BC
 * address:  0x020084BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Original (24 bytes, leaf, no relocations):
 *   movs r2, #0
 *  .loop:
 *   lsls r1, r2, #1
 *   ldrh r1, [r0, r1]
 *   cmp  r1, #0
 *   beq  .next
 *   movs r0, #0
 *   bx   lr
 *  .next:
 *   adds r2, r2, #1
 *   cmp  r2, #8
 *   blt  .loop
 *   movs r0, #1
 *   bx   lr
 *
 * "Are all eight halfwords zero".  Two details pin the source down: blt
 * rather than blo means the counter is a signed int, and the early return
 * inside the loop rather than a flag variable is what puts the `movs r0, #0;
 * bx lr` pair in the middle of the body.
 *
 * The address immediately after this function, 0x020084D4, carries another
 * function that disasm.py did not label (it has no register-saving
 * prologue, it is a tail call through bx r3), so tools/match.py reports the
 * listing extent as 56 bytes and flags the verdict EXACT* rather than
 * EXACT.  The 24 bytes compared are the whole of this function.
 */

typedef unsigned short u16;

int sub_020084BC(const u16 *values)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (values[i] != 0) {
            return 0;
        }
    }
    return 1;
}
