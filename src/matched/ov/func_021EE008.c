/*
 * function: func_021EE008
 * address:  0x021EE008
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EB85C  0x021EB85C  thumb  ov170
 *   func_021EDFC4  0x021EDFC4  thumb  ov170
 *   func_021EC000  0x021EC000  thumb  ov170
 *
 * Two-way: with flag 1 run the pair update, otherwise release slot 3
 *   and post 0 to the p+0x2c+4 object.
 */


extern void func_021EB85C(char *, int);
extern void func_021EDFC4(char *, int);
extern void func_021EC000(int, int, int);
extern void func_02025774(int, int);
void func_021EE008(char *p, int a, int b)
{
    if (b == 1) {
        func_021EB85C(p, a);
        func_021EDFC4(p, a);
        return;
    }
    func_021EC000(*(int *)(p + 0x2c), 3, 0);
    func_02025774(*(int *)(*(int *)(p + 0x2c) + 4), 0);
}
