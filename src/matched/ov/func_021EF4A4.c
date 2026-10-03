/*
 * function: func_021EF4A4
 * address:  0x021EF4A4
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
 * Probe the 8-byte tag at the top of the frame; 1 when its first
 *   byte is 6.
 */


typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
int func_021EF4A4(struct WinMgr *mgr)
{
    s8 buf[4];
    func_0202CF98(mgr, 8, buf + 1, buf);
    return buf[0] == 6;
}
