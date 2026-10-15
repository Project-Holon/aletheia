/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.  Not an SDK symbol: it is absent from
 * layout/symbols_sdk.txt.
 *
 * function: RECORD_GetSize
 * address:  0x02008C20
 * packet:   pkt_02008A34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Original (6 bytes, leaf, no relocations):
 *   movs r0, #0x1e
 *   lsls r0, r0, #4
 *   bx   lr
 *
 * The first function of the save block with id 0x26: it returns the block's
 * own size, 0x1E0, which is what the constructor at 0x02008C28 clears.  0x1E0
 * has no Thumb immediate encoding, so it arrives as a `movs` of 0x1E and a
 * shift rather than out of a literal pool; a pool would have cost four bytes
 * more and this compiler prefers the shift for any constant it can build in
 * two instructions.
 *
 * The rest of the file is src/matched/unit_02008C58.c; see its header for the
 * block layout and for the near miss that separates the two.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02008C20Obj {
    u32 unk000[0x47];
    u16 unk11C[0x60];
    u16 unk1DC;
    u16 unk1DE;
};

u32 RECORD_GetSize(void)
{
    return sizeof(struct Sub02008C20Obj);
}
