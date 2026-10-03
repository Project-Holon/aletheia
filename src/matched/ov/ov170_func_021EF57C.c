/*
 * function: func_021EF57C
 * address:  0x021EF57C
 * packet:   pkt_ov170_021EF57C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0202CF98 0x0202CF98 thumb
 *   func_0202CD64 0x0202CD64 thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
struct WinMgr;
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);

void func_021EF57C(struct WinMgr *mgr)
{
    signed char buf[2];
    unsigned short i = 0;
    func_0202CF98(mgr, 0, &buf[1], &buf[0]);
    if (buf[1] == 0x20)
        return;
    for (; i < 6; i++)
        func_0202CD64(mgr, i, 1, 0, 0x20 - buf[1]);
}
