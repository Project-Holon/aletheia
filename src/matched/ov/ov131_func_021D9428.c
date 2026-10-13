/*
 * function: P_STA_RIBBON_GetRowOwnedIndex
 * address:  0x021D9428
 * packet:   pkt_021D9428
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   P_STA_RIBBON_GetOwnedIndex  0x021D93E4  thumb
 *
 * Addresses are Black-image addresses.
 */

extern unsigned int P_STA_RIBBON_GetOwnedIndex(unsigned char *, unsigned int);

unsigned int P_STA_RIBBON_GetRowOwnedIndex(unsigned char *p, unsigned int target)
{
    unsigned int r = P_STA_RIBBON_GetOwnedIndex(p, target);

    if (r < p[0x10])
        return r;
    return 0xffff;
}
