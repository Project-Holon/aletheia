/*
 * function: func_021DFA60
 * address:  0x021DFA60
 * packet:   pkt_ov093_021DFA60
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
 */

extern int func_021D775C(int key);
extern void func_021D7704(int key, int m);

void func_021DFA60(int a, int b, int c)
{
    int n = 2;

    if (c == func_021D775C(n))
        func_021D7704(53, n << 10);
}
