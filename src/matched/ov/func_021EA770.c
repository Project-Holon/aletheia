/*
 * function: BOX2_SEQ_StopRightBar
 * address:  0x021EA770
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_PutTopBarClosed  0x021EF33C  thumb  ov170
 *   BOX2_SEQ_HideSlotsC6F4  0x021EC6F4  thumb  ov170
 *
 * Resume one 0x74 sub-object, then the plain resume.
 */
#include "../include/Obj18493.h"



struct WinMgr;
extern void BOX2_UI_PutTopBarClosed(struct WinMgr *mgr);
extern void BOX2_SEQ_HideSlotsC6F4(char *p);
void BOX2_SEQ_StopRightBar(int p)
{
    BOX2_UI_PutTopBarClosed(*(struct WinMgr **)(((struct Obj18493 *)p)->f2C + 0x74));
    BOX2_SEQ_HideSlotsC6F4((char *)p);
}
