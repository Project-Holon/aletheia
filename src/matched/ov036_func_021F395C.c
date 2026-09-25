/*
 * function: func_021F395C
 * address:  0x021F395C
 * packet:   pkt_ov036_021F395C
 * region:   ov036
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cross-overlay collision: the same address is also resident in ov043, so the
 * file and packet carry the region to keep them distinct.
 */

int func_021F395C(unsigned char *p, int idx)
{
    if (idx > p[0x1f])
        return 0;
    if (idx < 0)
        return 0;
    p[idx] = p[p[0x1f]];
    if (p[0x1f] != 0)
        p[0x1f] = p[0x1f] - 1;
    return 1;
}
