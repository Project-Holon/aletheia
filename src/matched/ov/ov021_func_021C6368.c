/*
 * function: SWEET_SCENT_FadeCleanup
 * address:  0x021C6368
 * packet:   pkt_ov021_021C6368
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_LoadPltt  0x02040E78  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BG_SYS_SetTileUnit  0x02040DA8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 x;
    u16 y;
} Pt;

typedef unsigned int   u32;
extern void BG_SYS_LoadPltt(u32 r7, void *r6, u32 r5, u32 r4);
extern void BG_SYS_SetTileEntry(int, int, int, int, int, int, int);
extern void BG_SYS_PushTile(u32 index);
extern void BG_SYS_SetTileUnit(u32 idx, u32 count, u32 tile);

void SWEET_SCENT_FadeCleanup(u8 *p)
{
    Pt pt = {0, 0};

    BG_SYS_LoadPltt(p[0], &pt, 8, 0x20);
    BG_SYS_SetTileEntry(p[0], 0, 0, 0, 0x20, 0x20, 1);
    BG_SYS_PushTile(p[0]);
    BG_SYS_SetTileUnit(p[0], 1, 0x100);
}
