/*
 * function: func_0215F3B8
 * address:  0x0215F3B8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call on the object at 0x021AA4B8 with the incoming argument.
 *
 * symbols:
 *   g_021AA4B8  0x021AA4B8  data
 *   func_0215F334  0x0215F334  arm  ov009
 */

extern char g_021AA4B8[];
extern void func_0215F334(char *p, int a);

void func_0215F3B8(int a)
{
    func_0215F334(g_021AA4B8, a);
}

