/*
 * unit:     no
 * function: BG_SYS_DecodeTileSource
 * address:  0x02040AF0
 * packet:   pkt_020409E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   BG_SYS_SetupMemory  0x02040968  arm
 *
 * Decode a tile source straight into slot `index`'s tile buffer at a tile
 * offset.  The offset scales by two, so the buffer is addressed in
 * halfwords here even though BG_SYS_PushTileSource treats the same field as an
 * opaque destination.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_DecodeTileSource.c \
 *       --func BG_SYS_DecodeTileSource --addr 0x02040AF0 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u8   pad_00[8];
    u16 *tiles;
    u8   pad_0c[0x20];
};

extern struct Slot *g_02146A44;

extern void BG_SYS_SetupMemory(const void *src, void *dst, u32 mode);

void BG_SYS_DecodeTileSource(u32 index, const void *src, u32 mode, u32 offset)
{
    BG_SYS_SetupMemory(src, g_02146A44[index].tiles + offset, mode);
}
