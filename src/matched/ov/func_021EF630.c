/*
 * function: BOX2_UI_AddFadeFrame
 * address:  0x021EF630
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BGWINFRM_AddFrame  0x0202CA3C  thumb  arm9
 *   BGWINFRM_SetFrameData  0x0202CAC4  thumb  arm9
 *   BG_SYS_GetBuf  0x0204162C  arm  arm9
 *
 * Spin up the 0x0204162C resource, arm channel 6 with tag 0x20,
 *   then hand row 6 of the 0x540 span.
 */
#include "../include/Obj01558.h"


typedef unsigned int u32;
struct WinMgr;
extern u32 BG_SYS_GetBuf(int channel);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void BGWINFRM_SetFrameData(struct WinMgr *mgr, u32 idx, const void *src);
void BOX2_UI_AddFadeFrame(char *p)
{
    int x = BG_SYS_GetBuf(0);
    BGWINFRM_AddFrame(*(struct WinMgr **)(*(int *)&((struct Obj01558 *)p)->f2C + 0x74), 6, 0, 0x20, 3);
    BGWINFRM_SetFrameData(*(struct WinMgr **)(*(int *)&((struct Obj01558 *)p)->f2C + 0x74), 6, (const void *)(x + 0x540));
}
