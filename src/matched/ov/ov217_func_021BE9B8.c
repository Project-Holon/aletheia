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
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   RESEARCH_GRAPH_SetHighlightB 0x021BEB88 thumb ov217
 */
#include "../include/Obj25909.h"
#include "../include/G_E.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 x,y,w,h; u8 rest[32]; } E;
extern struct E d_021C3AC8[];
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32);
extern u32 RESEARCH_GRAPH_SetHighlightB(u32);
void RESEARCH_GRAPH_DrawIndexCursorDim(u8 *p)
{
    switch (((struct Obj25909 *)p)->f34) {
    case 0:
    case 2:
    case 3:
        func_020413B0(2, d_021C3AC8[*(u32 *)(p + 52)].a,
            d_021C3AC8[*(u32 *)(p + 52)].b,
            d_021C3AC8[*(u32 *)(p + 52)].c,
            d_021C3AC8[*(u32 *)(p + 52)].d, 6);
        break;
    case 1:
        func_020413B0(2,13,4,19,4,6);
        func_020413B0(2,16,8,16,3,6);
        break;
    case 4:
        RESEARCH_GRAPH_SetHighlightB((u32)p);
        break;
    }
    func_020409B4(2);
}
