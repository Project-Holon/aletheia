/*
 * function: BOX2_UI_PutInfoBar
 * address:  0x021EF738
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BGWINFRM_PutFrame  0x0202CB4C  thumb  arm9
 *   BGWINFRM_StartMove  0x0202CD64  thumb  arm9
 *
 * Stage row 0x20 at channel 9 then patch with -1.
 */


typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
void BOX2_UI_PutInfoBar(struct WinMgr *mgr)
{
    BGWINFRM_PutFrame(mgr, 9, 0x20, 0);
    BGWINFRM_StartMove(mgr, 9, -1, 0, 0xb);
}
