/*
 * function: func_021AF294
 * address:  0x021AF294
 * packet:   pkt_ov021_021AF294
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AF1E8  0x021AF1E8  thumb  ov021
 *   func_021AF21C  0x021AF21C  thumb  ov021
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 func_02159B10(u32 a, u32 b);
extern u32 func_0215A5F4(u32 a);
extern void func_021AF1E8(u32 a);
extern void func_020061E4(u32 a);
extern void func_021AF21C(u32 a, u32 b);

int func_021AF294(u32 a, u32 b)
{
    u32 x = func_02159B10(a, b);
    u32 y = func_0215A5F4(b);

    func_021AF1E8(y);
    func_020061E4(x);
    func_021AF21C(y, x);
    return 0;
}
