/*
 * function: func_021AE8D4
 * address:  0x021AE8D4
 * packet:   pkt_ov021_021AE8D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_021AE79C  0x021AE79C  thumb  ov021
 *   func_021AE884  0x021AE884  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern u32 func_0216D67C(u32 a, u32 b);
extern u32 func_0216DD1C(u32 a, u32 *out, u32 *iter);
extern u32 func_021AE79C(u32 a);
extern u32 func_021AE884(u32 a);

u32 func_021AE8D4(u32 a, u32 b)
{
    u32 out;
    u32 iter;
    u32 h;

    iter = 0;
    h = func_0216D67C(a, 0);
    while (func_0216DD1C(h, &out, &iter) == 1) {
        if (out != a && (u16)(func_021AE79C(out) + 0xFFFF) <= 1 && b == func_021AE884(out)) {
            return out;
        }
    }
    return 0;
}
