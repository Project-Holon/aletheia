/*
 * function: func_021C06FC
 * address:  0x021C06FC
 * packet:   pkt_021C06FC
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BFCE4  0x021BFCE4  thumb  ov210
 *   func_021BF728  0x021BF728  thumb  ov210
 */

extern void func_021BFCE4(int a, signed char b);
extern void func_021BF728(int a, int b);

void func_021C06FC(int a, int b)
{
    func_021BFCE4(a, -b);
    func_021BF728(a, 1);
}
