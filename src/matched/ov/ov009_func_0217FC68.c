/*
 * function: B64InitEncodeStream
 * address:  0x0217FC68
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Stores the three argument words at the object.
 */

void B64InitEncodeStream(int *p, int a, int b, int c)
{
    p[0] = a;
    p[1] = b;
    p[2] = c;
}
