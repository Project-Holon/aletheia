/*
 * function: WEATHER_TASK_DisableFog
 * address:  0x021A231C
 * packet:   pkt_ov021_021A231C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_FOG_SetFlag  0x021A01A4  thumb  ov021
 */

typedef unsigned int u32;

int FIELD_FOG_SetFlag(u32 a, u32 b);

void WEATHER_TASK_DisableFog(u32 *p, int x)
{
    if (x == 1)
        FIELD_FOG_SetFlag(p[1], 0);
}
