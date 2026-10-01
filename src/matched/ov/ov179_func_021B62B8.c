/*
 * function: func_021B62B8
 * address:  0x021B62B8
 * packet:   pkt_ov179_021B62B8
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

void func_021B62B8(char *p, u32 a, u32 b, u32 c)
{
    func_0202208C(0, 0, 0, 0, a, b, 0x7f);
    *(u32 *)(p + 0x6054) = c;
}
