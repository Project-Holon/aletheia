/*
 * function: BG_SYS_CommitLayers
 * address:  0x02041A1C
 * packet:   pkt_020416D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   BG_SYS_LoadTileLayer  0x0204241C  arm
 *
 * Flush the eight tile slots of the 0x2c-byte table behind 0x02146A44 whose
 * dirty bit is set in the u16 at +6: each selected slot re-uploads its tile
 * buffer at the same argument triple BG_SYS_PushTileSource uses (index, tiles,
 * unk_10 * 2, unk_0c).  The global is re-read once per arm because the call
 * may write it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_CommitLayers.c \
 *       --func BG_SYS_CommitLayers --addr 0x02041A1C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u16   heapId;
    u16   unk_02;
    u16   unk_04;
    u16   unk_06;
    void *tiles;
    u32   unk_0c;
    u32   unk_10;
    u8    pad_14[0x18];
};

extern struct Slot *g_02146A44;

extern void BG_SYS_LoadTileLayer(u32 index, const void *src, u32 offset, u32 size);

void BG_SYS_CommitLayers(void)
{
    if (g_02146A44->unk_06 & 0x01)
        BG_SYS_LoadTileLayer(0, g_02146A44[0].tiles, g_02146A44[0].unk_10 * 2,
                      g_02146A44[0].unk_0c);
    if (g_02146A44->unk_06 & 0x02)
        BG_SYS_LoadTileLayer(1, g_02146A44[1].tiles, g_02146A44[1].unk_10 * 2,
                      g_02146A44[1].unk_0c);
    if (g_02146A44->unk_06 & 0x04)
        BG_SYS_LoadTileLayer(2, g_02146A44[2].tiles, g_02146A44[2].unk_10 * 2,
                      g_02146A44[2].unk_0c);
    if (g_02146A44->unk_06 & 0x08)
        BG_SYS_LoadTileLayer(3, g_02146A44[3].tiles, g_02146A44[3].unk_10 * 2,
                      g_02146A44[3].unk_0c);
    if (g_02146A44->unk_06 & 0x10)
        BG_SYS_LoadTileLayer(4, g_02146A44[4].tiles, g_02146A44[4].unk_10 * 2,
                      g_02146A44[4].unk_0c);
    if (g_02146A44->unk_06 & 0x20)
        BG_SYS_LoadTileLayer(5, g_02146A44[5].tiles, g_02146A44[5].unk_10 * 2,
                      g_02146A44[5].unk_0c);
    if (g_02146A44->unk_06 & 0x40)
        BG_SYS_LoadTileLayer(6, g_02146A44[6].tiles, g_02146A44[6].unk_10 * 2,
                      g_02146A44[6].unk_0c);
    if (g_02146A44->unk_06 & 0x80)
        BG_SYS_LoadTileLayer(7, g_02146A44[7].tiles, g_02146A44[7].unk_10 * 2,
                      g_02146A44[7].unk_0c);
}
