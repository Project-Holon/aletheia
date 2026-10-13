/*
 * function: WEATHER_TASK_InitFog
 * address:  0x021A22E0
 * packet:   pkt_ov021_021A22E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_FOG_SetBlendMode  0x021A01AC  thumb  ov021
 *   FIELD_FOG_SetColorA  0x021A01CC  thumb  ov021
 *   FIELD_FOG_SetSlope  0x021A01B4  thumb  ov021
 *   FIELD_FOG_SetOffset  0x021A01BC  thumb  ov021
 *   FIELD_FOG_InitFogTable  0x021A01D8  thumb  ov021
 *   FIELD_FOG_SetFlag  0x021A01A4  thumb  ov021
 */

typedef unsigned int u32;

int FIELD_FOG_SetBlendMode(u32 a, u32 b);
int FIELD_FOG_SetColorA(u32 a, u32 b);
int FIELD_FOG_SetSlope(u32 a, u32 b);
int FIELD_FOG_SetOffset(u32 a, u32 b);
typedef unsigned char  u8;
void FIELD_FOG_InitFogTable(u8 *p);
int FIELD_FOG_SetFlag(u32 a, u32 b);

void WEATHER_TASK_InitFog(u32 *p, int a, int b, int c)
{
    if (c == 1) {
        FIELD_FOG_SetBlendMode(p[1], 0);
        FIELD_FOG_SetColorA(p[1], 0x1F);
        FIELD_FOG_SetSlope(p[1], a);
        FIELD_FOG_SetOffset(p[1], b);
        FIELD_FOG_InitFogTable((u8 *)p[1]);
        FIELD_FOG_SetFlag(p[1], 1);
    }
}
