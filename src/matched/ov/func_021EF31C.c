/*
 * function: BOX2_UI_SetFrameData
 * address:  0x021EF31C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BGWINFRM_SetFrameDataArc  0x0202CAE4  thumb  arm9
 *
 * Forward the three arguments with a literal third argument, in place of the fourth.
 */

typedef unsigned int u32;
struct WinMgr;
extern void BGWINFRM_SetFrameDataArc(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);

void BOX2_UI_SetFrameData(struct WinMgr *mgr, int a1, int a2)
{
    BGWINFRM_SetFrameDataArc(mgr, a1, 0x74, a2, 1);
}

