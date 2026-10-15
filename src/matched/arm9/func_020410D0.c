/*
 * unit:     no
 * function: BG_SYS_DrawTileEx
 * address:  0x020410D0
 * packet:   pkt_02040F84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   BG_SYS_BlitTiles  0x020426A0  arm
 *   BG_SYS_BlitPixels  0x020428E8  arm
 *   BG_SYS_BlitTilesEx  0x02042B24  arm
 *
 * The ten-argument sibling of src/pending/BG_SYS_SetTileEntry.c: fan out on the
 * bit-depth byte at +0x1c of the 0x2c-byte slot behind 0x02146A44 and forward
 * the whole argument list, plus a trailing zero, to one of three blitters.
 * All three arms are byte-identical in their argument marshalling; only the
 * callee differs.
 *
 * The slot's sub-object pointer is spelled as byte arithmetic with the
 * constant added first and written out in every arm, for the reason recorded
 * in src/pending/BG_SYS_SetTileEntry.c: `&g_02146A44[index].unk_08` contracts into
 * a single `mla` and loses twelve bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_DrawTileEx.c \
 *       --func BG_SYS_DrawTileEx --addr 0x020410D0 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry {
    u8 pad_00[8];
    u8 unk_08[0x14];
    u8 unk_1c;
    u8 pad_1d[0xf];
};

extern struct Entry *g_02146A44;

extern void BG_SYS_BlitTiles(void *surf, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                          u8 a6, u8 a7, u8 a8, u8 a9, u32 a10);
extern void BG_SYS_BlitPixels(void *surf, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                          u8 a6, u8 a7, u8 a8, u8 a9, u32 a10);
extern void BG_SYS_BlitTilesEx(void *surf, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                          u8 a6, u8 a7, u8 a8, u8 a9, u32 a10);

void BG_SYS_DrawTileEx(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6,
                   u8 a7, u8 a8, u8 a9)
{
    u8 kind = g_02146A44[index].unk_1c;

    if (kind == 0) {
        BG_SYS_BlitTiles((u8 *)g_02146A44 + 8 + index * sizeof(struct Entry),
                      a1, a2, a3, a4, a5, a6, a7, a8, a9, 0);
    } else if (kind == 1) {
        BG_SYS_BlitPixels((u8 *)g_02146A44 + 8 + index * sizeof(struct Entry),
                      a1, a2, a3, a4, a5, a6, a7, a8, a9, 0);
    } else {
        BG_SYS_BlitTilesEx((u8 *)g_02146A44 + 8 + index * sizeof(struct Entry),
                      a1, a2, a3, a4, a5, a6, a7, a8, a9, 0);
    }
}
