/*
 * function: func_021EF4E4
 * address:  0x021EF4E4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Twin of func_021EF4C0 with the row tag 0x15.
 */


typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
void func_021EF4E4(struct WinMgr *mgr)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        func_0202CB4C(mgr, i, 0x15, (signed char)(i * 3 + 2));
}
