/*
 * function: func_021BD394
 * address:  0x021BD394
 * packet:   pkt_021BD368
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD404 0x021BD404  thumb  ov208
 *   func_021BD844 0x021BD844  thumb  ov208
 */

extern int func_021BD404(int, int);
extern void func_021BD844(int, int);

void func_021BD394(int a, int b, int c)
{
    func_021BD844(func_021BD404(a, b), c);
}

