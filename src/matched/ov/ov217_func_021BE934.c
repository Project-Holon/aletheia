/*
 * function: RESEARCH_GRAPH_DrawIndexCursor
 * address:  0x021BE934
 * packet:   pkt_ov217_021BE934
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C3AC8     0x021C3AC8  data  a1
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   RESEARCH_GRAPH_SetHighlightA  0x021BEB6C  thumb  ov217
 *
 * Case 4 passes the context pointer through to RESEARCH_GRAPH_SetHighlightA (r0 is still
 * live), which keeps the switch value in r1.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25908.h"

typedef unsigned char u8;

/* d_021C3AC8 (arm9), same object as research_graph.c's CursorLayoutRow: x,y,w,h
 * tile rect then eight words. */
struct CursorLayoutRow { u8 x, y, w, h; int offsets[8]; };

extern struct CursorLayoutRow d_021C3AC8[];
typedef unsigned int   u32;
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern int BG_SYS_PushTile(int);
extern u32 RESEARCH_GRAPH_SetHighlightA(u32 a0);

int RESEARCH_GRAPH_DrawIndexCursor(char *p)
{
    switch (((struct Obj25908 *)p)->f34) {
    case 0:
    case 2:
    case 3:
        BG_SYS_FillTileMap(2, d_021C3AC8[*(int *)(p + 0x34)].x,
                      d_021C3AC8[*(int *)(p + 0x34)].y,
                      d_021C3AC8[*(int *)(p + 0x34)].w,
                      d_021C3AC8[*(int *)(p + 0x34)].h, 0xa);
        break;
    case 1:
        BG_SYS_FillTileMap(2, 0xd, 4, 0x13, 4, 0xa);
        BG_SYS_FillTileMap(2, 0x10, 8, 0x10, 3, 0xa);
        break;
    case 4:
        RESEARCH_GRAPH_SetHighlightA((u32)p);
        break;
    }
    return BG_SYS_PushTile(2);
}
