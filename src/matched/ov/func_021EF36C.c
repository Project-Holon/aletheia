/*
 * function: func_021EF36C
 * address:  0x021EF36C
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
 * Probe the 8-byte tag; unless the tag byte is 6, patch the row
 *   with (tag - 6) through channel 8.
 */


typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
void func_021EF36C(struct WinMgr *mgr)
{
    s8 buf[4];
    func_0202CF98(mgr, 8, buf + 1, buf);
    if ((signed char)buf[0] != 6)
        func_0202CD64(mgr, 8, 0, -1, (unsigned char)(buf[0] - 6));
}
