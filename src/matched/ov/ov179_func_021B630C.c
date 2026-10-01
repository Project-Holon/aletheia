/*
 * function: func_021B630C
 * address:  0x021B630C
 * packet:   pkt_ov179_021B630C
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202208C  0x0202208C  thumb
 */
typedef unsigned int u32;

extern void func_0202208C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

void func_021B630C(char *p, u32 a, u32 b, u32 c)
{
    func_0202208C(0, 0, 0, 0x7fff, a, b, 0x7f);
    *(u32 *)(p + 0x6054) = c;
}
