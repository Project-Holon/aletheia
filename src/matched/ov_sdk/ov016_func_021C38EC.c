/*
 * function: func_021C38EC
 * address:  0x021C38EC
 * packet:   pkt_ov016_021C38EC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit (libdwcutil.TWL.HYB.a(sceneoptmovconfi))
 * symbols:
 *   func_021D55A4  0x021D55A4  arm
 *   func_021D603C  0x021D603C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm
 *   func_021C3954  0x021C3954  arm
 */
extern void func_021D55A4(int a, int b, int c, int d);
extern void func_021D603C(int a, int b);
extern void func_021C0E40(unsigned int v);
extern void func_021C3954(void);

void func_021C38EC(void)
{
    func_021D55A4(2, 1, 1, 8);
    func_021D55A4(2, 0, 0x15, 8);
    func_021D603C(1, 1);
    func_021D603C(0, 0x15);
    func_021C0E40((unsigned int)func_021C3954);
}
