/*
 * function: func_021EDA70
 * address:  0x021EDA70
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC0B0  0x021EC0B0  thumb  ov170
 *
 * Scan six 0x2d-spaced panel rows for the (a1+1)*0x22 key and clear
 *   both shorts when nothing matched.  The key must be written as an
 *   ASSIGNMENT TO THE PARAMETER,
 *       a1 = (a1 + 1) * 0x22;
 *   then tested as `if (a1 == a3[0])`.  A separate `int k = ...` local
 *   loses the image's two-instruction parameter home (r6 = a1, r1 =
 *   r6+1, r6 = r1, muls r6) and swaps a2/a3 between r6 and r7.
 */

extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
void func_021EDA70(int a0, int a1, short *a2, short *a3)
{
    unsigned i;
    a1 = (a1 + 1) * 0x22;
    for (i = 0; i < 6; i++) {
        func_021EC0B0((char *)a0, i + 0x2d, a2, a3, 0);
        if (a1 == a3[0])
            return;
    }
    *a2 = 0;
    *a3 = 0;
}

