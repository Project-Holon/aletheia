/*
 * function: WEATHER_TASK_IsZoneFogActive
 * address:  0x021A23D4
 * packet:   pkt_ov021_021A23D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_ZONEFOG_IsLoadRequest  0x021A0354  thumb  ov021
 */

typedef unsigned char  u8;
u8 FIELD_ZONEFOG_IsLoadRequest(u8 *p);

int WEATHER_TASK_IsZoneFogActive(int *p)
{
    if (FIELD_ZONEFOG_IsLoadRequest((u8 *)p[4]) == 1) {
        return 1;
    }
    return 0;
}
