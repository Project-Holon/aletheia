/*
 * function: FIELD_ZONEFOG_IsFog
 * address:  0x021A0380
 * packet:   pkt_ov021_021A0380
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf, filed as a blocker of the ov024/ov025 lane S26.
 *
 * symbols:
 *   FIELD_ZONEFOG_IsFog  0x021A0380  thumb  ov021
 */

int FIELD_ZONEFOG_IsFog(int *p)
{
    return p[1] != 0 ? 1 : 0;
}
