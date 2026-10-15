/*
 * function: setsockopt
 * address:  0x0217ECF8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call with the constant pair (0, -1).
 *
 * symbols:
 *   CheckRcode  0x0217EB00  arm
 */

extern int CheckRcode(int a, int b);

void setsockopt(void)
{
    CheckRcode(0, -1);
}

