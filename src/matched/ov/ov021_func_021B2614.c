/*
 * function: func_021B2614
 * address:  0x021B2614
 * packet:   pkt_ov021_021B2614
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011330  0x02011330  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021F3A28  0x021F3A28  thumb  ov043
 */

typedef unsigned int u32;

extern u32 func_0215A5F4(u32);
extern u32 func_0215A5DC(u32);
extern u32 func_02011330(u32);
extern u32 func_021F3A28(u32, u32);
extern void func_0215897C(u32, u32);

int func_021B2614(u32 a, u32 b)
{
    u32 s = func_0215A5F4(b);
    u32 d = func_0215A5DC(b);
    u32 r = func_021F3A28(d, func_02011330(a) ? 1 : 0);

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, r);
    return 1;
}
