/*
 * function: DWCi_WStrLen
 * address:  0x021686E0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the index of the first zero halfword in the array.
 *
 * symbols:
 *

 */

int DWCi_WStrLen(unsigned short *p)
{
    int i = 0;

    while (p[i] != 0) i++;
    return i;
}


