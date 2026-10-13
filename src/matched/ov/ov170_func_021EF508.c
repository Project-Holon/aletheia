/*
 * function: func_021EF508
 * address:  0x021EF508
 * packet:   pkt_ov170_021EF508
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BGWINFRM_HideFrame 0x0202CC70 thumb
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 */

typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);

void func_021EF508(struct WinMgr *mgr)
{
    unsigned i;
    for (i = 0; i < 6; i++) {
        BGWINFRM_HideFrame(mgr, i);
        BGWINFRM_PutFrame(mgr, i, 0x20, i * 3 + 2);
    }
}
