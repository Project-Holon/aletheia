/*
 * function: func_021834D0
 * address:  0x021834D0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Fills the three words at +8, +0xc and +0x10 with -1 and reports success.
 */

int func_021834D0(int *p)
{
    p[2] = -1;
    p[3] = -1;
    p[4] = -1;
    return 1;
}
