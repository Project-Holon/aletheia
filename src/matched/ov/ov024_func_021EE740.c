/*
 * function: WEATHER_CLEAR_Begin
 * address:  0x021EE740
 * packet:   pkt_ov024_021EE740
 * region:   ov024
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WEATHER_TASK_IsZoneFogActive  0x021A23D4  thumb  ov021
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_IsZoneFog  0x021A23E8  thumb  ov021
 *   WEATHER_TASK_GetZoneFogOffset  0x021A2400  thumb  ov021
 *   WEATHER_TASK_GetZoneFogSlope  0x021A240C  thumb  ov021
 *   WEATHER_TASK_InitFog  0x021A22E0  thumb  ov021
 */

int WEATHER_TASK_IsZoneFogActive(int *p);
int *WEATHER_TASK_GetWorkBuffer(int *p);
int WEATHER_TASK_IsZoneFog(int *p);
int WEATHER_TASK_GetZoneFogOffset(int *p);
int WEATHER_TASK_GetZoneFogSlope(int *p);
typedef unsigned int   u32;
void WEATHER_TASK_InitFog(u32 *p, int a, int b, int c);

int WEATHER_CLEAR_Begin(int *p, int v)
{
    if (WEATHER_TASK_IsZoneFogActive(p)) {
        return 0;
    }
    *WEATHER_TASK_GetWorkBuffer(p) = 0;
    if (WEATHER_TASK_IsZoneFog(p)) {
        WEATHER_TASK_GetZoneFogOffset(p);
        WEATHER_TASK_InitFog((u32 *)p, WEATHER_TASK_GetZoneFogSlope(p), 0x7FFF, v);
    }
    return 1;
}
