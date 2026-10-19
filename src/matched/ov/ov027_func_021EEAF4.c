/*
 * function: WEATHER_SANDSTORM_ScrollBillboards
 * address:  0x021EEAF4
 * packet:   pkt_ov027_021EEAF4
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The handed 332-byte extent is 82 bytes of code followed by the ov027
 * data tables (0x021EEB48 onward).
 *
 * symbols:
 *   WEATHER_TASK_GetCameraScroll  0x021A244C  thumb  ov021
 *   WEATHER_TASK_ShiftParticles  0x021A2564  thumb  ov021
 *   WEATHER_TASK_SetBillboardTexOffsetX  0x021A2190  thumb  ov021
 *   WEATHER_TASK_SetBillboardTexOffsetY  0x021A21A0  thumb  ov021
 */

typedef signed int     s32;
typedef unsigned char  u8;
extern void WEATHER_TASK_GetCameraScroll(u8 *o, s32 *outX, s32 *outY);
extern void WEATHER_TASK_ShiftParticles(int, int, int);
extern void WEATHER_TASK_SetBillboardTexOffsetX(unsigned char *o, unsigned int v, int i);
extern void WEATHER_TASK_SetBillboardTexOffsetY(unsigned char *o, unsigned int v, int i);

void WEATHER_SANDSTORM_ScrollBillboards(int a, int *s)
{
    int x;
    int y;

    WEATHER_TASK_GetCameraScroll((u8 *)a, &x, &y);
    WEATHER_TASK_ShiftParticles(a, x, y);
    s[2] = (s[2] + 6) % 256;
    WEATHER_TASK_SetBillboardTexOffsetX((unsigned char *)a, -s[2] * 2 - x, 0);
    WEATHER_TASK_SetBillboardTexOffsetY((unsigned char *)a, y + -s[2] * 2, 0);
}
