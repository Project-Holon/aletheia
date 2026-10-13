/*
 * function: WEATHER_TASK_ResetLight
 * address:  0x021A2120
 * packet:   pkt_ov021_021A2120
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_LIGHT_ReloadZoneTable  0x021A05D8  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
void FIELD_LIGHT_ReloadZoneTable(u8 *a);

void WEATHER_TASK_ResetLight(u32 *p, int x)
{
    if (x == 1)
        FIELD_LIGHT_ReloadZoneTable((u8 *)p[2]);
}
