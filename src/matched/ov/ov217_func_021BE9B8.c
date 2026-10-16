/*
 * function: RESEARCH_GRAPH_DrawIndexCursorDim
 * address: 0x021BE9B8
 * packet: pkt_ov217_021BE9B8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C3AC8 0x021C3AC8 data a1
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   RESEARCH_GRAPH_SetHighlightB 0x021BEB88 thumb ov217
 */
#include "../include/Obj25909.h"
typedef unsigned char u8;
typedef unsigned int u32;
/* d_021C3AC8 (arm9), same object as research_graph.c's CursorLayoutRow: x,y,w,h
 * tile rect then eight words. */
struct CursorLayoutRow { u8 x,y,w,h; int offsets[8]; };
extern struct CursorLayoutRow d_021C3AC8[];
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BG_SYS_PushTile(u32);
extern u32 RESEARCH_GRAPH_SetHighlightB(u32);
void RESEARCH_GRAPH_DrawIndexCursorDim(u8 *p)
{
    switch (((struct Obj25909 *)p)->f34) {
    case 0:
    case 2:
    case 3:
        BG_SYS_FillTileMap(2, d_021C3AC8[*(u32 *)(p + 52)].x,
            d_021C3AC8[*(u32 *)(p + 52)].y,
            d_021C3AC8[*(u32 *)(p + 52)].w,
            d_021C3AC8[*(u32 *)(p + 52)].h, 6);
        break;
    case 1:
        BG_SYS_FillTileMap(2,13,4,19,4,6);
        BG_SYS_FillTileMap(2,16,8,16,3,6);
        break;
    case 4:
        RESEARCH_GRAPH_SetHighlightB((u32)p);
        break;
    }
    BG_SYS_PushTile(2);
}
