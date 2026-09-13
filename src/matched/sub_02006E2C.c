/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/000_02004000.s.
 *
 * function: sub_02006E2C
 * address:  0x02006E2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Original (20 bytes, leaf, one ABS32 literal):
 *   ldr  r0, [pc, #0xc]   ; &sub_02006E2C_Ptr
 *   movs r1, #0x1f
 *   ldr  r0, [r0]
 *   ldr  r0, [r0, #0x24]
 *   adds r0, #0x1f
 *   bics r0, r1
 *   bx   lr
 *
 * Round a size up to a multiple of 32.  The mask is materialised in r1 and
 * applied with bics because Thumb has no immediate form of bic; the
 * compiler hoists the movs above both loads, which is the schedule the
 * original shows.
 */

typedef unsigned int u32;

struct Sub02006E2CObj {
    u32 unk00[9];
    u32 unk24;
};

extern struct Sub02006E2CObj *sub_02006E2C_Ptr;

u32 sub_02006E2C(void)
{
    return (sub_02006E2C_Ptr->unk24 + 0x1F) & ~0x1Fu;
}
