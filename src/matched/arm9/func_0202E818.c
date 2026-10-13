/*
 * function: COMM_PLAYER_SUPPORT_HasSavedMode
 * address:  0x0202E818
 * packet:   pkt_0202E818
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf: nonzero if either of two words at +4 or +8 is set.
 */

int COMM_PLAYER_SUPPORT_HasSavedMode(int *p)
{
    if (p[1] != 0 || p[2] != 0)
        return 1;
    return 0;
}
