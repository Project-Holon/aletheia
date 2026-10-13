/*
 * function: INTRUDE_COMM_GetNotice
 * address:  0x0217537C
 * packet:   pkt_ov011_0217537C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf, the follower of INTRUDE_COMM_ClearNotice (same +0x15C field):
 * returns the field's address when its first byte is 1, else null.
 * Labelled so that INTRUDE_COMM_ClearNotice's extent ends at its own pool.
 *
 * Addresses are Black-image addresses.
 */

unsigned char *INTRUDE_COMM_GetNotice(unsigned char *p)
{
    if (p[0x15C] == 1) {
        return p + 0x15C;
    }
    return 0;
}
