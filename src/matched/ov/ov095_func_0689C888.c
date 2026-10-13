/*
 * function: BTL_ID_IsInList
 * address:  0x0689C888
 * packet:   pkt_0689C888
 * region:   ov095
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

int BTL_ID_IsInList(unsigned a, unsigned short *b, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++) {
        if (a == b[i])
            return 1;
    }
    return 0;
}
