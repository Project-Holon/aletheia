/*
 * function: func_021B11D8
 * address:  0x021B11D8
 * packet:   pkt_ov021_021B11D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02011330  0x02011330  thumb
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02159168  0x02159168  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0219196C  0x0219196C  thumb  ov021
 *   func_021919AC  0x021919AC  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_0215A5F4(u32);
extern u32 *func_02158F58(u32);
extern u32 func_02011330(u32);
extern void func_0219196C(u32, u32);
extern u32 func_021919AC(u32);
extern void func_02159168(u32);

int func_021B11D8(u32 a, u32 b)
{
    u32 *p = func_02158F58(func_0215A5F4(b));

    func_0219196C(*p, func_02011330(a));
    if (func_021919AC(*p) == 0) {
        func_02159168(5);
    }
    return 0;
}
