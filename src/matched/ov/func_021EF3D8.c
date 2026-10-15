/*
 * function: BOX2_UI_SlideBarIn
 * address:  0x021EF3D8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BGWINFRM_StartMove  0x0202CD64  thumb  arm9
 *
 * Forward a plus constants to BGWINFRM_StartMove.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);

void BOX2_UI_SlideBarIn(struct WinMgr *mgr)
{
    BGWINFRM_StartMove(mgr, 8, 1, 0, 0x13);
}

