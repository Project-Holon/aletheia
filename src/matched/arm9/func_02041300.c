/*
 * function: BG_SYS_SetTileEntry
 * address:  0x02041300
 * packet:   pkt_02041300
 * isa:      arm
 * status:   EXACT
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * symbols:
 *   g_BgConfig     0x02146A44  data
 *   BG_SYS_BlitTileMap  0x02042D2C  arm
 *   BG_SYS_BlitPixelsEx  0x02042E34  arm
 *   BG_SYS_BlitTileMapEx  0x02042ED8  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

struct BgConfigLayer {
    char pad_00[0x1C];
    u8 mode;
    char pad_1D[0x0F];
};

extern struct BgConfigLayer *g_BgConfig;

extern void BG_SYS_BlitTileMap(void *p, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void BG_SYS_BlitPixelsEx(void *p, u8 a1, int a2, int a3, u8 a4, u8 a5);
extern void BG_SYS_BlitTileMapEx(void *p, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);

void BG_SYS_SetTileEntry(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6)
{
    u32 offset = layer * 0x2C;
    struct BgConfigLayer *bg = (struct BgConfigLayer *)((u8 *)g_BgConfig + offset);

    if (bg->mode == 0) {
        BG_SYS_BlitTileMap((u8 *)g_BgConfig + 8 + offset, a1, a2, a3, a4, a5, a6);
    } else if (bg->mode == 1) {
        BG_SYS_BlitPixelsEx((u8 *)g_BgConfig + 8 + offset, (u8)a1, a2, a3, a4, a5);
    } else {
        BG_SYS_BlitTileMapEx((u8 *)g_BgConfig + 8 + offset, a1, a2, a3, a4, a5, a6);
    }
}
