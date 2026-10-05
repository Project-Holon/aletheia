/*
 * function: func_021DF228
 * address:  0x021DF228
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021DF1BC  0x021DF1BC  thumb  ov170
 *
 * Scan the six 4-byte entries of the third argument; the first one that
 * func_021DF1BC accepts returns i + 0x1e, else 0xff.
 */

extern int func_021DF1BC(int a, int b, unsigned char *r);


int func_021DF228(void *p, int a, int *b)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        if (func_021DF1BC((int)p, a, (unsigned char *)(b + i)) == 1)
            return i + 0x1e;
    return 0xff;
}
