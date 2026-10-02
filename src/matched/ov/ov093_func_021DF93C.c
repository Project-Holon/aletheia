/*
 * function: func_021DF93C
 * address:  0x021DF93C
 * packet:   pkt_ov093_021DF93C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021DD008  0x021DD008  thumb  ov093
 */

extern int func_021D775C(int key);
extern void func_021D7704(int key, int m);
extern int func_021DD008(int a);

void func_021DF93C(int a, int b, int c, int d)
{
    if (c != func_021D775C(3))
        return;
    if (d != func_021D775C(22))
        return;
    func_021D7704(49, func_021DD008(a));
}
