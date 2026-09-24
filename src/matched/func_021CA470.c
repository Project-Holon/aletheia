/*
 * function: func_021CA470
 * address:  0x021CA470
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CA240  0x021CA240  arm  ov114
 *
 *
 * Forwards five arguments and a zero tail to func_021CA240.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021CA240(int, int, int, int, int, int);

void func_021CA470(int a, int b, int c, int d, int e)
{
    func_021CA240(a, b, c, d, e, 0);
}
