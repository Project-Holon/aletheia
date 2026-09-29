/*
 * function: func_021AE9F0
 * address:  0x021AE9F0
 * packet:   pkt_ov021_021AE9F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159124  0x02159124  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern u32 func_0215A5F4(u32 a);
extern u32 func_02159B10(u32 a, u32 b);
extern u16 *func_02159AE8(u32 a, u32 b);
extern u32 *func_02159124(u32 a, u32 b);

int func_021AE9F0(u32 a, u32 b)
{
    u32 p, k;
    u16 *out;
    u32 *e;

    p = func_0215A5F4(b);
    k = func_02159B10(a, b);
    out = func_02159AE8(a, b);
    e = 0;
    if (k == 0) {
        e = func_02159124(p, 0);
    } else if (k == 1) {
        e = func_02159124(p, 1);
    }
    *out = e ? e[4] : 0;
    return 0;
}
