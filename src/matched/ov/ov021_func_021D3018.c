/*
 * function: func_021D3018
 * address:  0x021D3018
 * packet:   pkt_ov021_021D3018
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021F3A44  0x021F3A44  thumb  ov064
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_0215A5DC(u32 a);
extern int func_02159B10(u32 a, u32 b);
extern void func_021F3A44(u32 a, int *v);

u32 func_021D3018(u32 a, u32 b)
{
    int v[3];
    u32 s0;
    int r6;
    int r7;
    int z;

    s0 = func_0215A5DC(b);
    r6 = func_02159B10(a, b);
    r7 = func_02159B10(a, b);
    z = func_02159B10(a, b);
    v[0] = (r6 << 16) + 0x8000;
    v[1] = r7 << 15;
    v[2] = (z << 16) + 0x8000;
    func_021F3A44(s0, v);
    return 0;
}
