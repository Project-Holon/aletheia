/*
 * function: func_021EF660
 * address:  0x021EF660
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *
 * Forward a plus constants to func_0202CB4C.
 */

typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);

void func_021EF660(struct WinMgr *mgr)
{
    func_0202CB4C(mgr, 6, 0, 0x15);
}

