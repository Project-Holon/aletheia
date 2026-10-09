/*
 * file:     unit_0219B7FC.c
 * function: func_0219B7FC
 * address:  0x0219B7FC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Swaps two bytes.
 */

void func_0219B7FC(unsigned char *p, unsigned char *q)
{
    unsigned char t = *p;

    *p = *q;
    *q = t;
}
