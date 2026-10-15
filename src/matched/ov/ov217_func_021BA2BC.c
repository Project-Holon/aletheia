/*
 * function: RESEARCH_TOP_DrawSelectorIdle
 * address:  0x021BA2BC
 * packet:   pkt_ov217_021BA2BC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BG_SYS_FillTileMap  0x020413B0  arm  arm9
 *   BG_SYS_PushTile  0x020409B4  arm  arm9
 */

extern void BG_SYS_FillTileMap(int, int, int, int, int, int);
typedef unsigned int   u32;
extern void BG_SYS_PushTile(u32 index);

void RESEARCH_TOP_DrawSelectorIdle(int sel)
{
    int a, b, c, d, e, f;
    switch (sel) {
    case 0:
        a = 2; b = 3; c = 5; d = 0x1a; e = 5; f = 5;
        break;
    case 1:
        a = 2; b = 3; c = 0xc; d = 0x1a; e = 5; f = 6;
        break;
    default:
        return;
    }
    BG_SYS_FillTileMap(a, b, c, d, e, f);
    BG_SYS_PushTile(a);
}
