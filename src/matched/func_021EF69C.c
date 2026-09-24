/*
 * function: func_021EF69C
 * address:  0x021EF69C
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
 * Forward the word at +0x74 with index 11.
 */

extern void func_0202CC70(int, int);

void func_021EF69C(char *p)
{
    func_0202CC70(*(int *)(p + 0x74), 0xb);
}

