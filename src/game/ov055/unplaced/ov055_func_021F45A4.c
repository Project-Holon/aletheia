/*
 * function: func_021F45A4
 * address:  0x021F45A4
 * packet:   pkt_ov055_021F45A4
 * region:   ov055
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219196C  0x0219196C  thumb  ov021
 *   func_021F459C  0x021F459C  thumb  ov055
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0219196C(u32 a, u32 b);
extern void func_021F459C(void *p);

void func_021F45A4(u16 *p, u32 x)
{
    if (p[0] != 0) {
        func_0219196C(x, p[2]);
        func_021F459C(p);
    }
}
