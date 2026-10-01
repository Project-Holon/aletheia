/*
 * function: func_021B1BB8
 * address:  0x021B1BB8
 * packet:   pkt_ov021_021B1BB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02158F90  0x02158F90  thumb  ov010
 *   func_0215A5EC  0x0215A5EC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_021B1B08  0x021B1B08  thumb  ov021
 */

typedef unsigned int u32;

extern u32 func_0215A5F4(u32);
extern u32 func_02158F90(u32);
extern u32 func_0215A5EC(u32);
extern void func_0216D9A0(u32);
extern int func_021B1B08(int, int);

int func_021B1BB8(int a, int b)
{
    if (func_02158F90(func_0215A5F4(b)) == 0) {
        func_0216D9A0(func_0215A5EC(b));
    } else {
        return func_021B1B08(a, b);
    }
    return 0;
}
