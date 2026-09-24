/*
 * function: func_0215F0C8
 * address:  0x0215F0C8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Rounds an address up to the next word boundary.
 */

unsigned func_0215F0C8(unsigned addr)
{
    return (addr + 3) & ~3u;
}
