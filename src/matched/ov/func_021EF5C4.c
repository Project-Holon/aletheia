/*
 * function: func_021EF5C4
 * address:  0x021EF5C4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BGWINFRM_UpdateMove  0x0202CDD4  thumb  arm9
 *
 * 1 when probe 1..6 reports 1.
 */


typedef unsigned int u32;
struct WinMgr;
extern u32 BGWINFRM_UpdateMove(struct WinMgr *mgr, u32 idx);
int func_021EF5C4(struct WinMgr *mgr)
{
    unsigned i;
    int found = 0;
    for (i = 0; i < 6; i++) {
        if (BGWINFRM_UpdateMove(mgr, i) == 1)
            found = 1;
    }
    return found;
}
