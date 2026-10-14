/*
 * function: CircleGraph_SumValues
 * address:  0x021C1AD4
 * packet:   pkt_ov217_021C1AD4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

int CircleGraph_SumValues(u8 *p)
{
    int i;
    int n;
    int sum;
    n = p[0x1AC];
    sum = 0;
    for (i = 0; i < n; i++)
        sum += *(int *)(p + i * 0x14 + 0x20);
    return sum;
}
