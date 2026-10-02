/*
 * function: func_021E1BD4
 * address:  0x021E1BD4
 * packet:   pkt_ov093_021E1BD4
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
 */

extern int func_021D775C(int key);
extern int func_021D76BC(int a, int b);

void func_021E1BD4(int a, int b, int c)
{
    if (c == func_021D775C(2) && func_021D775C(34) == 2)
        func_021D76BC(65, 1);
}
