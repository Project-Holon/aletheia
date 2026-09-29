/*
 * function: func_021C341C
 * address:  0x021C341C
 * packet:   pkt_ov021_021C341C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0200BCA8  0x0200BCA8  thumb
 *   func_0200BC2C  0x0200BC2C  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200BCD8  0x0200BCD8  thumb
 *   func_021C3510  0x021C3510  thumb  ov021
 *   func_0201850C  0x0201850C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0200BCA8(u32);
extern u32 func_0200BC2C(u32, u32);
extern u32 func_02017E1C(u32, u32, u32);
extern u32 func_0200BCD8(u32, u32);
extern u32 func_021C3510(u32, u32);
extern int func_0201850C(u16, u16, u32);

int func_021C341C(u32 *p, u32 b)
{
    u32 m;
    u32 s0;
    u32 s1;
    u32 s2;

    if (func_0200BCA8(p[2]) != 1)
        return 1;
    m = func_0200BC2C(p[2], b);
    s2 = func_02017E1C(m, 5, 0);
    s0 = func_02017E1C(m, 0x6F, 0);
    s1 = func_02017E1C(m, 8, 0);
    func_02017E1C(m, 0x9E, 0);
    return func_0201850C(s2, s0, func_021C3510(s1, func_0200BCD8(p[2], b)));
}
