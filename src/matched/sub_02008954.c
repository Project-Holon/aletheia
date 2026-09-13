/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.
 *
 * function: sub_02008954
 * address:  0x02008954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Original (8 bytes, leaf, no relocations):
 *   adds r0, #0x73
 *   ldrb r0, [r0]
 *   strb r0, [r1]
 *   bx   lr
 *
 * A byte field copied out through a caller-supplied pointer.  The add is
 * forced by the encoding: Thumb ldrb has a 5-bit immediate offset, so
 * anything past +0x1F needs the base computed first.  That is why the
 * offset 0x73 is visible in the instruction stream at all.
 */

typedef unsigned char u8;

struct Sub02008954Obj {
    u8 unk00[0x73];
    u8 unk73;
};

void sub_02008954(const struct Sub02008954Obj *obj, u8 *dst)
{
    *dst = obj->unk73;
}
