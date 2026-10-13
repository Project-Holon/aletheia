/*
 * function: func_021EF6A8
 * address:  0x021EF6A8
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
 * Stage rows 0x15/0x18 at channel 7 then patch with -1.
 */


typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
void func_021EF6A8(struct WinMgr *mgr)
{
    BGWINFRM_PutFrame(mgr, 7, 0x15, 0x18);
    BGWINFRM_StartMove(mgr, 7, 0, -1, 0x13);
}
