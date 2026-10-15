/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.  Not an SDK symbol: it is absent from
 * layout/symbols_sdk.txt.
 *
 * function: CGEAR_SAVE_GetSize
 * address:  0x020090B0
 * packet:   pkt_02008FD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Original (4 bytes, leaf, no relocations):
 *   movs r0, #0x2c
 *   bx   lr
 *
 * The size-returning opener of the next file in the chain, and the value the
 * constructor at 0x020090B4 clears.  The accessors over the object are in
 * src/matched/unit_020090D8.c, which also says why the constructor between the
 * two is not matched here.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub020090B0Obj {
    u8  unk00[9][4];
    u16 unk24;
    u8  unk26;
    u8  unk27;
    u8  unk28;
    u8  unk29[3];
};

u32 CGEAR_SAVE_GetSize(void)
{
    return sizeof(struct Sub020090B0Obj);
}
