/*
 * function: BTL_SETUP_GetParty
 * address:  0x0201313C
 * packet:   pkt_0201313C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf: the i-th pointer of the table at +0x24.
 */

void *BTL_SETUP_GetParty(void *p, int i)
{
    return ((void **)((char *)p + 0x24))[i];
}
