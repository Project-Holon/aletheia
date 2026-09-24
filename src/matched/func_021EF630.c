/*
 * function: func_021EF630
 * address:  0x021EF630
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Spin up the 0x0204162C resource, arm channel 6 with tag 0x20,
 *   then hand row 6 of the 0x540 span.
 */


extern int func_0204162C(int);
extern void func_0202CA3C(int, int, int, int, int);
extern void func_0202CAC4(int, int, int);
void func_021EF630(char *p)
{
    int x = func_0204162C(0);
    func_0202CA3C(*(int *)(*(int *)(p + 0x2c) + 0x74), 6, 0, 0x20, 3);
    func_0202CAC4(*(int *)(*(int *)(p + 0x2c) + 0x74), 6, x + 0x540);
}
