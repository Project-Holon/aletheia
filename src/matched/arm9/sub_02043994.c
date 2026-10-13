/*
 * function: BMP_GetTileBytes
 * address:  0x02043994
 * packet:   pkt_0204384C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * bmp.c's accessor for the halfword at +8, the field the blit dispatcher at
 * 0x020439A0 compares between source and destination.  The `ldrh` followed
 * by `and r0, r0, #0xff` is the field's own width against the function's:
 * the field is a halfword and the return type is a byte, so the truncation
 * is at the return, not at the load.  No relocation.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_GetTileBytes.c \
 *       --func BMP_GetTileBytes --addr 0x02043994 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Bmp {
    u8  pad00[8];
    u16 unk08;
    u16 unk0A;
};

u8 BMP_GetTileBytes(struct Bmp *b)
{
    return b->unk08;
}
