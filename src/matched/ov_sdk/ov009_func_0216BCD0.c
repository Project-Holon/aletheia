/*
 * function: DWCi_GetAIDBitmapFromList
 * address:  0x0216BCD0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Builds a bit mask over the first n bytes of the array: m |= 1 << p[i].
 *
 * symbols:
 *

 */

int DWCi_GetAIDBitmapFromList(unsigned char *p, int n)
{
    int m = 0;
    int i;

    for (i = 0; i < n; i++)
        m |= 1 << p[i];
    return m;
}


