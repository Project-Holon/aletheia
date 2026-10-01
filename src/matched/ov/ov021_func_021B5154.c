/*
 * function: func_021B5154
 * address:  0x021B5154
 * packet:   pkt_ov021_021B5154
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200D418  0x0200D418  thumb
 *   func_0200D488  0x0200D488  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215E440  0x0215E440  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u32 func_0215A5E4(u32);
extern u32 func_02012EBC(u32);
extern u32 func_0200D418(u32);
extern u32 func_02159B10(u32, u32);
extern u32 func_0200D488(u32, u8);
extern void func_0215E440(u32, u8);

int func_021B5154(u32 a, u32 b)
{
    u32 e = func_0215A5E4(b);
    u32 g = func_0200D418(func_02012EBC(e));
    u8 k = func_02159B10(a, b);

    if (func_0200D488(g, k) == 0) {
        func_0215E440(e, k);
    }
    return 0;
}
