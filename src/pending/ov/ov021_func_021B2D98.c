/*
 * function: func_021B2D98
 * address:  0x021B2D98
 * packet:   pkt_ov021_021B2D98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0218BA98  0x0218BA98  thumb  ov021
 *   func_0218C860  0x0218C860  thumb
 *   func_021B2BD8  0x021B2BD8  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_02159B10(u32, u32);
extern u32 func_021B2BD8(u32);
extern u32 func_0218BA98(u32, u32);
extern void func_0218C860(u32);

int func_021B2D98(u32 a, u32 b)
{
    u32 x = func_02159B10(a, b);
    u32 o = func_0218BA98(func_021B2BD8(b), x);

    if (o != 0) {
        func_0218C860(o);
    }
    return 0;
}
