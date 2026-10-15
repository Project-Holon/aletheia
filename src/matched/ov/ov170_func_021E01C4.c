/*
 * function: BOX2_MAIN_ShiftWindowRight
 * address:  0x021E01C4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_MoveSlotIcon  0x021ED918  thumb  ov170
 *   BGWINFRM_UpdateMove  0x0202CDD4  thumb  arm9
 *
 * Query entry 9, then flag state 8.
 */
#include "../include/Obj03849.h"



typedef unsigned int u32;
struct WinMgr;
extern u32 BGWINFRM_UpdateMove(struct WinMgr *mgr, u32 idx);
extern void BOX2_UI_MoveSlotIcon(char *, int);
int BOX2_MAIN_ShiftWindowRight(char *p)
{
    int v = BGWINFRM_UpdateMove(*(struct WinMgr **)(*(int *)&((struct Obj03849 *)p)->f2C + 0x74), 9);
    BOX2_UI_MoveSlotIcon(p, 8);
    return v;
}
