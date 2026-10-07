/*
 * function: func_021DFA88
 * address:  0x021DFA88
 * packet:   pkt_ov093_021DFA88
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
 *   func_021C818C  0x021C818C  thumb  ov093
 */

extern int func_021D775C(int key);
extern void func_021D7704(int key, int m);
extern int func_021C818C(unsigned char *p, int v);

void func_021DFA88(int a, unsigned char *b, int c)
{
    if (c == func_021D775C(4) && func_021C818C(b, c))
        func_021D7704(53, 6 << 10);
}
