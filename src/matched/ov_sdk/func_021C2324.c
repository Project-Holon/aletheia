/*
 * function: func_021C2324
 * address:  0x021C2324
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C2490  0x021C2490  arm  ov114
 *
 *
 * Null-guarded keyed apply of `b` onto object `a`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C2490(int, int);

void func_021C2324(int a, int b)
{
    if (b == 0)
        return;
    func_021C2490(a, b);
}
