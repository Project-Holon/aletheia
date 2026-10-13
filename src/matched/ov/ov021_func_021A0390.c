/*
 * function: FIELD_ZONEFOG_IsLight
 * address:  0x021A0390
 * packet:   pkt_ov021_021A0390
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, filed as a blocker of the ov024/ov025 lane S26.
 *
 * symbols:
 *   FIELD_ZONEFOG_IsLight  0x021A0390  thumb  ov021
 */

int FIELD_ZONEFOG_IsLight(int *p)
{
    return p[2] != 0x0FFFFFFF ? 1 : 0;
}
