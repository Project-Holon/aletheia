/*
 * function: BOX2_SEQ_StopLeftBar
 * address:  0x021EA75C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_PutTopBarOpen  0x021EF32C  thumb  ov170
 *   BOX2_SEQ_HideSlotsC688  0x021EC688  thumb  ov170
 *
 * Stop one 0x74 sub-object, then the plain stop.
 */
#include "../include/Obj18491.h"



struct WinMgr;
extern void BOX2_UI_PutTopBarOpen(struct WinMgr *mgr);
extern void BOX2_SEQ_HideSlotsC688(char *p);
void BOX2_SEQ_StopLeftBar(int p)
{
    BOX2_UI_PutTopBarOpen(*(struct WinMgr **)(((struct Obj18491 *)p)->f2C + 0x74));
    BOX2_SEQ_HideSlotsC688((char *)p);
}
