/*
 * function: func_02199284
 * address:  0x02199284
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Set when the six-byte test of the object at 0x021A5A7C fails.
 *
 * symbols:
 *   g_021A5A7C  0x021A5A7C  data
 */

extern char g_021A5A7C[];
extern int func_020923F0(int a, char *p, int n);

int func_02199284(int a)
{
    return func_020923F0(a, g_021A5A7C, 6) == 0;
}

