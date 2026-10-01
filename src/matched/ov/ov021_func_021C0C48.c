/*
 * function: func_021C0C48
 * address:  0x021C0C48
 * packet:   pkt_ov021_021C0C48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets mode 2 on each of the p[0x15] handles, then resets the one at +0x38.
 *
 * symbols:
 *   func_0218C88C  0x0218C88C  thumb  ov021
 */

typedef unsigned char u8;

extern void func_0218C88C(int a, int b, int c);

void func_021C0C48(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++)
        func_0218C88C(((int *)(p + 0x1C))[i], 0, 2);
    if (*(int *)(p + 0x34) != 0)
        func_0218C88C(*(int *)(p + 0x38), 0, 0);
}
