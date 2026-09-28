/*
 * function: func_021B1688
 * address:  0x021B1688
 * packet:   pkt_021B1688
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

void func_021B1688(unsigned char *dst, short *src, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        dst[i] = (signed char)(src[i] >> 8);
}
