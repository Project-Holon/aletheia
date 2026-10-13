/*
 * function: WEATHER_TASK_GetZoneFogC
 * address:  0x021A2400
 * packet:   pkt_ov021_021A2400
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
 *   WEATHER_TASK_GetZoneFogC  0x021A2400  thumb  ov021
 *   FIELD_ZONEFOG_GetFogOffset  0x021A03A4  thumb  ov021
 */

int FIELD_ZONEFOG_GetFogOffset(int *p);

int WEATHER_TASK_GetZoneFogC(int *p)
{
    return FIELD_ZONEFOG_GetFogOffset((int *)p[4]);
}
