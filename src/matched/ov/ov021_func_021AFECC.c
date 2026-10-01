/*
 * function: func_021AFECC
 * address:  0x021AFECC
 * packet:   pkt_ov021_021AFECC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021850A8  0x021850A8  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u32 func_0215A5F4(u32 a);
extern u32 func_02158F54(u32 a);
extern u32 func_0201210C(u32 a);
extern u32 func_02012104(u32 a);
extern u32 func_021850A8(u32 a, u32 b);
extern void func_02012374(u32 a, u32 b);

int func_021AFECC(u32 a, u32 b)
{
    u32 p = func_02158F54(func_0215A5F4(b));
    u32 q = func_0201210C(p);
    u32 r = func_02012104(p);

    func_02012374(r, func_021850A8(p, q));
    return 1;
}
