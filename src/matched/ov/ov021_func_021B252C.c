/*
 * function: func_021B252C
 * address:  0x021B252C
 * packet:   pkt_ov021_021B252C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021F4184  0x021F4184  thumb  ov039
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0215A5F4(u32);
extern u32 func_0215A5DC(u32);
extern u16 *func_02159AE8(u32, u32);
extern u32 func_021F4184(u32, u16);
extern void func_0215897C(u32, u32);

int func_021B252C(u32 a, u32 b)
{
    u32 s = func_0215A5F4(b);
    u32 d = func_0215A5DC(b);
    u32 r = func_021F4184(d, *func_02159AE8(a, b));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, r);
    return 1;
}
