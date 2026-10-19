/*
 * function: WEATHER_TASK_GetZoneFogLightId
 * address:  0x021A2418
 * packet:   pkt_ov021_021A2418
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
 *   WEATHER_TASK_GetZoneFogLightId  0x021A2418  thumb  ov021
 *   FIELD_ZONEFOG_GetLightId  0x021A03CC  thumb  ov021
 */

int FIELD_ZONEFOG_GetLightId(int *p);

int WEATHER_TASK_GetZoneFogLightId(int *p)
{
    return FIELD_ZONEFOG_GetLightId((int *)p[4]);
}
