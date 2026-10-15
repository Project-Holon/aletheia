/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.  Not an SDK symbol: it is absent from
 * layout/symbols_sdk.txt.
 *
 * function: CONSOLE_STAMP_GetSize
 * address:  0x02008AEC
 * packet:   pkt_02008A34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Original (4 bytes, leaf, no relocations):
 *   movs r0, #0x5c
 *   bx   lr
 *
 * The first function of the save block with id 0x25: it returns the block's
 * own size, which is what the constructor at 0x02008AF0 clears.  The rest of
 * the file is src/matched/unit_02008B08.c and
 * src/matched/unit_02008B4C.c; see the header of the latter for why the file
 * is committed in three pieces and what the block holds.
 */

typedef unsigned int u32;

/* Declared only so that the size below is a `sizeof` rather than a constant;
 * the full declaration is in src/matched/unit_02008B4C.c. */
struct Sub02008AECObj {
    unsigned char unk00[0x5C];
};

u32 CONSOLE_STAMP_GetSize(void)
{
    return sizeof(struct Sub02008AECObj);
}
