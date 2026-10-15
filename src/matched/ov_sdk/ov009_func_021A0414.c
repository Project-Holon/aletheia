/*
 * function: ServerSizeForFlags
 * address:  0x021A0414
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Maps the flag bits 2, 8, 0x10 and 0x20 to a size code starting at 5.
 *
 * symbols:
 *

 */

int ServerSizeForFlags(int f)
{
    int n = 5;

    if (f & 2) n += 4;
    if (f & 8) n += 4;
    if (f & 0x10) n += 2;
    if (f & 0x20) n += 2;
    return n;
}


