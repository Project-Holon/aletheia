/*
 * function: RESEARCH_TOP_UpdateFrameGraphic
 * address:  0x021B99EC
 * packet:   pkt_ov217_021B99EC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_TOP_GetFrameCount  0x021B9850  thumb  ov217
 *   _u32_div_f  0x0209C2B0  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm  arm9
 *   BG_SYS_PushTile  0x020409B4  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 RESEARCH_TOP_GetFrameCount(const void *p);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BG_SYS_PushTile(u32 index);

void RESEARCH_TOP_UpdateFrameGraphic(const void *p)
{
    u32 t = RESEARCH_TOP_GetFrameCount(p) / 10;
    u32 m = (u8)(t % 6);
    BG_SYS_FillTileMap(5, 0, 0, 0x20, 0x18, (u8)m);
    BG_SYS_PushTile(5);
}
