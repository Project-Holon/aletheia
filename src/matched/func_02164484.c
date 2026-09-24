/*
 * function: func_02164484
 * address:  0x02164484
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Halfword at p as the high word of a 64-bit value.
 *
 * symbols:

 */

unsigned long long func_02164484(unsigned short *p)
{
    return (unsigned long long)*p << 32;
}

