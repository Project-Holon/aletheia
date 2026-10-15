/*
 * function: gsiGetResolvedIP
 * address:  0x0217F1CC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Saves the word at +4, calls the helper and returns it.
 *
 * symbols:
 *   gsifree  0x0217EAE0  arm

 */

extern void gsifree(void *p);

int gsiGetResolvedIP(int *p)
{
    int v = p[1];

    gsifree(p);

    return v;
}

