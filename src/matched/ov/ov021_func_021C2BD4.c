/*
 * function: FLD3D_CI_IsAltFadeSequence
 * address:  0x021C2BD4
 * packet:   pkt_ov021_021C2BD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: true for the two ids 0xC and 0x13.
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

int FLD3D_CI_IsAltFadeSequence(u16 id)
{
    if (id == 0xc || id == 0x13)
        return 1;
    return 0;
}
