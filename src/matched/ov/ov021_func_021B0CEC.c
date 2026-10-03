/*
 * function: func_021B0CEC
 * address:  0x021B0CEC
 * packet:   pkt_ov021_021B0CEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A61C  0x0215A61C  thumb  ov010
 *   func_02191388  0x02191388  thumb
 *   func_021B0B08  0x021B0B08  thumb  ov021
 */

typedef unsigned int u32;

extern int func_0215A61C(int a0);
extern void func_021B0B08(u32, int);
extern u32 func_02191388(u32);

int func_021B0CEC(u32 a, u32 b)
{
    u32 t;

    t = func_0215A61C(b);
    func_021B0B08(b, 0);
    b = 0;
    if (func_02191388(t) == 1) {
        b = 1;
    }
    return b;
}
