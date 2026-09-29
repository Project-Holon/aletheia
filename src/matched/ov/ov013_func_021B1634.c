/*
 * function: func_021B1634
 * address:  0x021B1634
 * packet:   pkt_ov013_021B1634
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:

 */

void func_021B1634(unsigned char *src, short *dst, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++) {
        int u = ~src[i];
        int t = (((u & 0xf) << 3) + 0x84) << ((u & 0x70) >> 4);

        dst[i] = (u & 0x80) ? 0x84 - t : t - 0x84;
    }
}
