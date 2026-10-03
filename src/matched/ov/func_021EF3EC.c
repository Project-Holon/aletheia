/*
 * function: func_021EF3EC
 * address:  0x021EF3EC
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
 * Forward a plus constants to func_0202CD64.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);

void func_021EF3EC(struct WinMgr *mgr)
{
    func_0202CD64(mgr, 8, -1, 0, 0x13);
}

