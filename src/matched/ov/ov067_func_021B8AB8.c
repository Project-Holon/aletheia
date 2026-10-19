/*
 * function: FRAME_LIST_GetScrollBarTop
 * address: 0x021B8AB8
 * packet: pkt_ov067_021B8AB8
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FRAME_LIST_FindScrollBarEntry 0x021B8A88 thumb ov067
 *   SCROLLBAR_GetPosFromValue 0x0202EE0C thumb
 */
#include "../include/Obj09865.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void FRAME_LIST_FindScrollBarEntry(u8 *, u8 *, u8 *);
typedef unsigned int   u32;
extern u32 SCROLLBAR_GetPosFromValue(u32 a, u32 b, u32 c, u32 d, u32 e);
int FRAME_LIST_GetScrollBarTop(u8 *p)
{
    u8 b, a;
    FRAME_LIST_FindScrollBarEntry(p, &b, &a);
    return SCROLLBAR_GetPosFromValue(((struct Obj09865 *)p)->f64, ((struct Obj09865 *)p)->f62, b, a, p[0x12]);
}
