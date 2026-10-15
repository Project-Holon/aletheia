/*
 * function: BOX2_MAIN_SceneWaitScroll
 * address:  0x021E070C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_SceneApplyScroll  0x021E066C  thumb  ov170
 *   BOX2_UI_UpdateListPacks  0x021EF5C4  thumb  ov170
 *
 * 1 unless both queries come back zero.
 */
#include "../include/Obj18462.h"


struct WinMgr;
extern int BOX2_MAIN_SceneApplyScroll(char *);
extern int BOX2_UI_UpdateListPacks(struct WinMgr *mgr);
int BOX2_MAIN_SceneWaitScroll(char *p)
{
    if (BOX2_MAIN_SceneApplyScroll(p) == 0 && BOX2_UI_UpdateListPacks(*(struct WinMgr **)(((struct Obj18462 *)p)->f2C + 0x74)) == 0)
        return 0;
    return 1;
}
