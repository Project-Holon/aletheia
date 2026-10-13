/*
 * function: WEATHER_TASK_ChangeFogOffset
 * address:  0x021A2390
 * packet:   pkt_ov021_021A2390
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_FOG_GetSlope  0x021A01D4  thumb  ov021
 *   FIELD_FOG_FADE_Init  0x021A01FC  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
u32 FIELD_FOG_GetSlope(u8 *p);
void FIELD_FOG_FADE_Init(u8 *p, u32 a, u32 b, u32 c);

void WEATHER_TASK_ChangeFogOffset(u32 *p, int a, int b, int c)
{
    if (c == 1)
        FIELD_FOG_FADE_Init((u8 *)p[1], a, FIELD_FOG_GetSlope((u8 *)p[1]), b);
}
