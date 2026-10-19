/*
 * function: WEATHER_THUNDERSTORM_ScrollLayers
 * address:  0x021EEF0C
 * packet:   pkt_ov026_021EEF0C
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_THUNDERSTORM_ScrollLayers 0x021EEF0C thumb ov026
 *   WEATHER_TASK_GetCameraScroll 0x021A244C thumb ov021
 *   WEATHER_TASK_ShiftParticles 0x021A2564 thumb ov021
 *   WEATHER_TASK_SetBillboardTexOffsetX 0x021A2190 thumb ov021
 *   WEATHER_TASK_SetBillboardTexOffsetY 0x021A21A0 thumb ov021
 */

typedef signed int     s32;
typedef unsigned char  u8;
extern void WEATHER_TASK_GetCameraScroll(u8 *o, s32 *outX, s32 *outY);
extern void WEATHER_TASK_ShiftParticles(int, int, int);
extern void WEATHER_TASK_SetBillboardTexOffsetX(unsigned char *o, unsigned int v, int i);
extern void WEATHER_TASK_SetBillboardTexOffsetY(unsigned char *o, unsigned int v, int i);

void WEATHER_THUNDERSTORM_ScrollLayers(int a, int *b)
{
    int x;
    int y;

    WEATHER_TASK_GetCameraScroll((u8 *)a, &x, &y);
    WEATHER_TASK_ShiftParticles(a, x, y);
    b[1] = (b[1] + 9) % 256;
    WEATHER_TASK_SetBillboardTexOffsetX((unsigned char *)a, -(b[1] + x), 0);
    WEATHER_TASK_SetBillboardTexOffsetY((unsigned char *)a, y - b[1], 0);
}
