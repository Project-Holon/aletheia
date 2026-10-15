/*
 * function: gti2CreateConnectionObject
 * address:  0x02198028
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call with a constant 0xa0 argument.
 *
 * symbols:
 *   gsimalloc  0x0217EAB0  arm
 */

extern void gsimalloc(int v);

void gti2CreateConnectionObject(void)
{
    gsimalloc(0xa0);
}

