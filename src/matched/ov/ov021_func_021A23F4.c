/*
 * function: WEATHER_TASK_IsZoneFogLight
 * address:  0x021A23F4
 * packet:   pkt_ov021_021A23F4
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
 *   WEATHER_TASK_IsZoneFogLight  0x021A23F4  thumb  ov021
 *   FIELD_ZONEFOG_IsLight  0x021A0390  thumb  ov021
 */

int FIELD_ZONEFOG_IsLight(int *p);

int WEATHER_TASK_IsZoneFogLight(int *p)
{
    return FIELD_ZONEFOG_IsLight((int *)p[4]);
}
