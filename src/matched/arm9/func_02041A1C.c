/*
 * function: func_02041A1C
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
 *   func_0204241C  0x0204241C  arm
 *
 * Flush the eight tile slots of the 0x2c-byte table behind 0x02146A44 whose
 * dirty bit is set in the u16 at +6: each selected slot re-uploads its tile
 * buffer at the same argument triple func_020409E0 uses (index, tiles,
 * unk_10 * 2, unk_0c).  The global is re-read once per arm because the call
 * may write it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02041A1C.c \
 *       --func func_02041A1C --addr 0x02041A1C --cc 1.1p1 --arm
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

extern void func_0204241C(u32 index, const void *src, u32 offset, u32 size);

void func_02041A1C(void)
{
    if (g_02146A44->unk_06 & 0x01)
        func_0204241C(0, g_02146A44[0].tiles, g_02146A44[0].unk_10 * 2,
                      g_02146A44[0].unk_0c);
    if (g_02146A44->unk_06 & 0x02)
        func_0204241C(1, g_02146A44[1].tiles, g_02146A44[1].unk_10 * 2,
                      g_02146A44[1].unk_0c);
    if (g_02146A44->unk_06 & 0x04)
        func_0204241C(2, g_02146A44[2].tiles, g_02146A44[2].unk_10 * 2,
                      g_02146A44[2].unk_0c);
    if (g_02146A44->unk_06 & 0x08)
        func_0204241C(3, g_02146A44[3].tiles, g_02146A44[3].unk_10 * 2,
                      g_02146A44[3].unk_0c);
    if (g_02146A44->unk_06 & 0x10)
        func_0204241C(4, g_02146A44[4].tiles, g_02146A44[4].unk_10 * 2,
                      g_02146A44[4].unk_0c);
    if (g_02146A44->unk_06 & 0x20)
        func_0204241C(5, g_02146A44[5].tiles, g_02146A44[5].unk_10 * 2,
                      g_02146A44[5].unk_0c);
    if (g_02146A44->unk_06 & 0x40)
        func_0204241C(6, g_02146A44[6].tiles, g_02146A44[6].unk_10 * 2,
                      g_02146A44[6].unk_0c);
    if (g_02146A44->unk_06 & 0x80)
        func_0204241C(7, g_02146A44[7].tiles, g_02146A44[7].unk_10 * 2,
                      g_02146A44[7].unk_0c);
}
