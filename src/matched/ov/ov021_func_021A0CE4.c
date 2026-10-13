/*
 * function: FIELD_LIGHT_FADE_IsActive
 * address:  0x021A0CE4
 * packet:   pkt_ov021_021A0CE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf (ldrh; nonzero test), filed for the ov026 lane.
 *
 * symbols:
 *   FIELD_LIGHT_FADE_IsActive 0x021A0CE4 thumb ov021
 */

typedef unsigned short u16;

int FIELD_LIGHT_FADE_IsActive(u16 *p)
{
    if (*p != 0) {
        return 1;
    }
    return 0;
}
