/*
 * function: BOX2_UI_IsListClosed
 * address:  0x021EF60C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BGWINFRM_GetPos  0x0202CF98  thumb  arm9
 *
 * 1 when the tag's byte 1 is 0x15.
 */


typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void BGWINFRM_GetPos(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
int BOX2_UI_IsListClosed(struct WinMgr *mgr)
{
    s8 buf[4];
    BGWINFRM_GetPos(mgr, 0, buf + 1, buf);
    return buf[1] == 0x15;
}
