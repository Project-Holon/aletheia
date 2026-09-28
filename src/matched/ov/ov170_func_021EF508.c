/*
 * function: func_021EF508
 * address:  0x021EF508
 * packet:   pkt_ov170_021EF508
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202CC70 0x0202CC70 thumb
 *   func_0202CB4C 0x0202CB4C thumb
 */

extern void func_0202CC70(int mgr, unsigned i);
extern void func_0202CB4C(int mgr, unsigned i, int a, signed char b);

void func_021EF508(int mgr)
{
    unsigned i;
    for (i = 0; i < 6; i++) {
        func_0202CC70(mgr, i);
        func_0202CB4C(mgr, i, 0x20, i * 3 + 2);
    }
}
