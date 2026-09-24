/*
 * function: func_021BF6C4
 * address:  0x021BF6C4
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BF6EC  0x021BF6EC  arm  ov114
 *
 *
 * Forwards six arguments with a zero in the fourth slot.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BF6EC(int, int, int, int, int, int, int);

void func_021BF6C4(int a, int b, int c, int d, int e, int f)
{
    func_021BF6EC(a, b, c, 0, d, e, f);
}
