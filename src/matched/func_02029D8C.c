/*
 * function: func_02029D8C
 * address:  0x02029D8C
 * packet:   pkt_02029D8C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012984  0x02012984  thumb
 *   func_02029EB4  0x02029EB4  thumb
 *   func_020289F8  0x020289F8  thumb
 */

typedef unsigned int u32;

extern u32 func_02012984(u32 a);
extern u32 func_02029EB4(u32 a, u32 b, u32 c);
extern void func_020289F8(u32 a, int b, u32 c, int d, int e);

void func_02029D8C(u32 a0, u32 a1, u32 a2)
{
    u32 temp = func_02012984(a1);
    u32 res = func_02029EB4(a1, a2, temp);
    func_020289F8(a0, 5, res, 0x1e, 0);
}
