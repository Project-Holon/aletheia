/*
 * function: func_021DED28
 * address:  0x021DED28
 * packet:   pkt_ov093_021DED28
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021E8C9C  0x021E8C9C  thumb  ov093
 */

extern int func_021D775C(int key);
extern int func_021D76BC(int a, int b);
extern void func_021E8C9C(int *p, int v);

void func_021DED28(int a, int b, int c)
{
    int t;

    if (c == func_021D775C(3) && func_021D775C(0x1d) == 8) {
        t = func_021D775C(0x1e);
        func_021E8C9C(&t, 8);
        func_021D76BC(0x1e, t);
    }
}
