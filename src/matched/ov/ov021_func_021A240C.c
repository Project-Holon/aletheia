/*
 * function: WEATHER_TASK_GetZoneFogD
 * address:  0x021A240C
 * packet:   pkt_ov021_021A240C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub, filed as a blocker of the ov024 lane S26.
 *
 * symbols:
 *   WEATHER_TASK_GetZoneFogD  0x021A240C  thumb  ov021
 *   FIELD_ZONEFOG_GetFogSlope  0x021A03B8  thumb  ov021
 */

int FIELD_ZONEFOG_GetFogSlope(int *p);

int WEATHER_TASK_GetZoneFogD(int *p)
{
    return FIELD_ZONEFOG_GetFogSlope((int *)p[4]);
}
