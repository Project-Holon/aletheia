/*
 * function: func_021CFEA0
 * address:  0x021CFEA0
 * packet:   pkt_ov021_021CFEA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02009590  0x02009590  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0215A5F4(u32 a);
extern u32 func_0215A5DC(u32 a);
extern u32 func_02159B10(u32 a, u32 b);
extern u16 *func_02159AE8(u32 a, u32 b);
extern u32 func_020120F4(u32 a);
extern u32 func_02012EBC(u32 a);
extern u32 func_02009470(u32 a);
extern u32 func_02012944(u32 a);
extern u32 func_02009590(u32 a, u32 b, u32 c);

int func_021CFEA0(u32 a, u32 b)
{
    u32 x, k, h, g;
    u16 *out;

    func_0215A5F4(b);
    x = func_0215A5DC(b);
    k = func_02159B10(a, b);
    out = func_02159AE8(a, b);
    h = func_020120F4(x);
    g = func_02009470(func_02012EBC(h));
    *out = func_02009590(g, func_02012944(h), k);
    return 0;
}
