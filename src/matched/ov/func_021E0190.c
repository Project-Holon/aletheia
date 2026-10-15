/*
 * function: BOX2_MAIN_IsWindowMoving
 * address:  0x021E0190
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_UI_UpdateListPacks  0x021EF5C4  thumb  ov170
 *
 * 1 when the p+0x2c+0x74 object is live.
 */
#include "../include/Obj18461.h"


struct WinMgr;
extern int BOX2_UI_UpdateListPacks(struct WinMgr *mgr);
int BOX2_MAIN_IsWindowMoving(char *p)
{
    if (BOX2_UI_UpdateListPacks(*(struct WinMgr **)(((struct Obj18461 *)p)->f2C + 0x74)) != 0)
        return 1;
    return 0;
}
