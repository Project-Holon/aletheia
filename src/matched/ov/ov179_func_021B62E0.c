/*
 * function: func_021B62E0
 * address:  0x021B62E0
 * packet:   pkt_ov179_021B62E0
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

extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

void func_021B62E0(char *p, u32 a, u32 b, u32 c)
{
    func_0202208C(0, 1, 1, 0x7fff, a, b, 0x7f);
    *(u32 *)(p + 0x6054) = c;
}
