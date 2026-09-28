/*
 * function: func_0217537C
 * address:  0x0217537C
 * packet:   pkt_ov011_0217537C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf, the follower of func_02175368 (same +0x15C field):
 * returns the field's address when its first byte is 1, else null.
 * Labelled so that func_02175368's extent ends at its own pool.
 *
 * Addresses are Black-image addresses.
 */

unsigned char *func_0217537C(unsigned char *p)
{
    if (p[0x15C] == 1) {
        return p + 0x15C;
    }
    return 0;
}
