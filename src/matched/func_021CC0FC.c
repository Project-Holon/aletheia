/*
 * function: func_021CC0FC
 * address:  0x021CC0FC
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CBB80  0x021CBB80  arm  ov114
 *
 *
 * Forwards four arguments behind a leading zero to func_021CBB80.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021CBB80(int, int, int, int, int);

void func_021CC0FC(int a, int b, int c, int d)
{
    func_021CBB80(0, a, b, c, d);
}
