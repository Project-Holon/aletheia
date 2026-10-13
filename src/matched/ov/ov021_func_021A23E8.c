/*
 * function: WEATHER_TASK_CheckZoneFogA
 * address:  0x021A23E8
 * packet:   pkt_ov021_021A23E8
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
 *   WEATHER_TASK_CheckZoneFogA  0x021A23E8  thumb  ov021
 *   FIELD_ZONEFOG_IsFog  0x021A0380  thumb  ov021
 */

int FIELD_ZONEFOG_IsFog(int *p);

int WEATHER_TASK_CheckZoneFogA(int *p)
{
    return FIELD_ZONEFOG_IsFog((int *)p[4]);
}
