/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.  Not an SDK symbol: it is absent from
 * layout/symbols_sdk.txt.
 *
 * function: sub_02008534
 * address:  0x02008534
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Original (8 bytes, leaf, no relocations):
 *   ldr  r0, [r0, #0x10]
 *   lsls r0, r0, #0x10
 *   lsrs r0, r0, #0x10
 *   bx   lr
 *
 * A word field read back as a halfword.  The shift pair rather than a
 * mask means the truncation is a conversion in the type system, not an
 * explicit & 0xFFFF: writing the and produces a movs/ands pair instead.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02008534Obj {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
};

u16 sub_02008534(const struct Sub02008534Obj *obj)
{
    return (u16)obj->unk10;
}
