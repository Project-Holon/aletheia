/*
 * function: func_021C0A10
 * address:  0x021C0A10
 * packet:   pkt_ov021_021C0A10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Resets each of the p[0x15] handles, then the optional one at +0x34.
 *
 * symbols:
 *   func_0218C88C  0x0218C88C  thumb  ov021
 *   func_0218C69C  0x0218C69C  thumb  ov021
 */

typedef unsigned char u8;

extern void func_0218C88C(unsigned char *p, int v, int c);
extern void func_0218C69C(unsigned char *p, int b, int i, int c);

void func_021C0A10(u8 *p)
{
    int i;

    for (i = 0; i < p[0x15]; i++)
        func_0218C88C((unsigned char *)(((int *)(p + 0x1C))[i]), 0, 0);
    if (*(int *)(p + 0x34) != 0)
        func_0218C69C((unsigned char *)(*(int *)(p + 0x18)), *(int *)(p + 0x34), 0, 0);
}
