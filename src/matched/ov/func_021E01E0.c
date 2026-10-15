/*
 * function: BOX2_MAIN_ShiftWindowLeft
 * address:  0x021E01E0
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
 * Read status 9 from the p+0x2c+0x74 object, push frame -8, and
 *   return the status.
 */
#include "../include/Obj03849.h"


typedef unsigned int u32;
struct WinMgr;
extern u32 BGWINFRM_UpdateMove(struct WinMgr *mgr, u32 idx);
extern void BOX2_UI_MoveSlotIcon(char *, int);
int BOX2_MAIN_ShiftWindowLeft(char *p)
{
    int x = BGWINFRM_UpdateMove(*(struct WinMgr **)(*(int *)&((struct Obj03849 *)p)->f2C + 0x74), 9);
    BOX2_UI_MoveSlotIcon(p, -8);
    return x;
}
