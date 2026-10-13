/*
 * function: FIELD_ZONEFOG_GetFogSlope
 * address:  0x021A03B8
 * packet:   pkt_ov021_021A03B8
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
 *   FIELD_ZONEFOG_GetFogSlope  0x021A03B8  thumb  ov021
 */

int FIELD_ZONEFOG_GetFogSlope(int *p)
{
    int *q = (int *)p[1];

    if (q != 0) {
        return q[1];
    }
    return 0x0FFFFFFF;
}
