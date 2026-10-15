/*
 * function: BOX2_UI_IsInfoBarOpen
 * address:  0x021EF770
 * packet:   pkt_021EF770
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_IsInfoBarOpen 0x021EF770 thumb
 *   BGWINFRM_GetPos 0x0202CF98 thumb
 */

typedef signed char s8;

typedef unsigned int u32;
struct WinMgr;
extern void BGWINFRM_GetPos(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);

int BOX2_UI_IsInfoBarOpen(struct WinMgr *mgr)
{
    s8 buf[2];
    BGWINFRM_GetPos(mgr, 9, &buf[1], &buf[0]);
    if (buf[1] == 0x15) {
        return 1;
    }
    return 0;
}
