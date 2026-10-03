/*
 * function: func_021EF738
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
 *
 * Stage row 0x20 at channel 9 then patch with -1.
 */


typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
void func_021EF738(struct WinMgr *mgr)
{
    func_0202CB4C(mgr, 9, 0x20, 0);
    func_0202CD64(mgr, 9, -1, 0, 0xb);
}
