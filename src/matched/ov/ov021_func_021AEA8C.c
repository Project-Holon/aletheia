/*
 * function: func_021AEA8C
 * address:  0x021AEA8C
 * packet:   pkt_ov021_021AEA8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02158F8C  0x02158F8C  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A460  0x0215A460  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 func_0215A5F4(u32 a);
extern void func_02158F58(u32 a);
extern u32 func_02158F8C(u32 a);
extern u16 *func_02159AE8(u32 a, u32 b);
extern u16 func_0215A460(u32 a);

int func_021AEA8C(u32 a, u32 b)
{
    u32 x = func_0215A5F4(b);
    u32 y;

    func_02158F58(x);
    y = func_02158F8C(x);
    *func_02159AE8(a, b) = func_0215A460(y);
    return 0;
}
