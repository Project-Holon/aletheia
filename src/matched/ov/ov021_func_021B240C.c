/*
 * function: func_021B240C
 * address:  0x021B240C
 * packet:   pkt_ov021_021B240C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021F37C8  0x021F37C8  thumb  ov040
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0215A5F4(u32);
extern u32 func_0215A5DC(u32);
extern u32 func_0201210C(u32);
extern u16 *func_02159AE8(u32, u32);
extern u32 func_021F37C8(u32);

int func_021B240C(u32 a, u32 b)
{
    u32 w;
    u16 *o;

    func_0215A5F4(b);
    w = func_0201210C(func_0215A5DC(b));
    o = func_02159AE8(a, b);
    if (func_021F37C8(w) != 0) {
        *o = 1;
    } else {
        *o = 0;
    }
    return 0;
}
