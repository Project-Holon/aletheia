/*
 * function: func_021D9434
 * address:  0x021D9434
 * packet:   pkt_ov119_021D9434
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202208C  0x0202208C  thumb
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021D941C  0x021D941C  thumb  ov119
 *
 * Start a 7-argument timer/slot request (0,0,0,0,6,1,*(u16*)(p+0x5f4)) then
 * hand func_021D8E84 the func_021D941C callback. Non-SDK dep of
 * func_021DFDA0's case-5 arm.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

extern void func_0202208C(int, int, int, int, int, int, int);
extern void func_021D8E84(void *, int);
extern void func_021D941C(void);

void func_021D9434(void *p)
{
    func_0202208C(0, 0, 0, 0, 6, 1, *(u16 *)((char *)p + 0x5f4));
    func_021D8E84(p, (int)func_021D941C);
}
