/*
 * function: WF2DMAP_OBJDRAW_SetFrameDefault
 * address:  0x021C57DC
 * packet:   pkt_ov127_021C57DC
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Tail-call forwarder: (p) -> WF2DMAP_OBJDRAW_SetFrame(p, 1, p->u16 at +0xA).
 * Blocker of ov099 func_021B99F4 / func_021B9A70.
 *
 * symbols:
 *   WF2DMAP_OBJDRAW_SetFrame  0x021C5944  thumb  ov127
 */
#include "../include/Obj00328.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern void WF2DMAP_OBJDRAW_SetFrame(u8 *p, int one, int v);

void WF2DMAP_OBJDRAW_SetFrameDefault(u8 *p)
{
    WF2DMAP_OBJDRAW_SetFrame(p, 1, ((struct Obj00328 *)p)->fA);
}
