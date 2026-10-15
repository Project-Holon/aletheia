/*
 * function: WF2DMAP_OBJDRAW_SetFrameZero
 * address:  0x021C5864
 * packet:   pkt_021C5864
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WF2DMAP_OBJDRAW_SetFrame  0x021C5944  thumb
 *   func_021C42C4  0x021C42C4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00328.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void WF2DMAP_OBJDRAW_SetFrame(u8 *p, int n, int a);
extern void func_021C42C4(u8 *p);

void WF2DMAP_OBJDRAW_SetFrameZero(u8 *p, int b)
{
    WF2DMAP_OBJDRAW_SetFrame(p, 0, b);
    func_021C42C4(((struct Obj00328 *)p)->f4);
}
