/*
 * function: func_021EF680
 * address:  0x021EF680
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202CC70  0x0202CC70  thumb  ov170
 *
 * Forward the word at +0x74 with index 10.
 */

extern void func_0202CC70(int, int);

void func_021EF680(char *p)
{
    func_0202CC70(*(int *)(p + 0x74), 0xa);
}

