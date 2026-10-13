/*
 * function: WEATHER_CLEAR_BeginPlain
 * address:  0x021EE7F0
 * packet:   pkt_ov024_021EE7F0
 * region:   ov024
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   WEATHER_CLEAR_BeginPlain  0x021EE7F0  thumb  ov024
 *   WEATHER_TASK_CheckZoneFogA  0x021A23E8  thumb  ov021
 *   WEATHER_TASK_GetZoneFogC  0x021A2400  thumb  ov021
 *   WEATHER_TASK_GetZoneFogD  0x021A240C  thumb  ov021
 *   WEATHER_TASK_InitFog  0x021A22E0  thumb  ov021
 *   WEATHER_TASK_CheckZoneFogB  0x021A23F4  thumb  ov021
 *   WEATHER_TASK_GetZoneFogE  0x021A2418  thumb  ov021
 *   WEATHER_TASK_SetLight  0x021A2114  thumb  ov021
 */

typedef unsigned int   u32;
int WEATHER_TASK_CheckZoneFogA(int *p);
int WEATHER_TASK_GetZoneFogC(int *p);
int WEATHER_TASK_GetZoneFogD(int *p);
void WEATHER_TASK_InitFog(u32 *p, int a, int b, int c);
int WEATHER_TASK_CheckZoneFogB(int *p);
int WEATHER_TASK_GetZoneFogE(int *p);
int WEATHER_TASK_SetLight(u32 a, int b, u32 c);

int WEATHER_CLEAR_BeginPlain(int p, int v)
{
    int t;

    if (WEATHER_TASK_CheckZoneFogA((int *)p)) {
        t = WEATHER_TASK_GetZoneFogC((int *)p);
        WEATHER_TASK_InitFog((u32 *)p, WEATHER_TASK_GetZoneFogD((int *)p), t, v);
    }
    if (WEATHER_TASK_CheckZoneFogB((int *)p)) {
        WEATHER_TASK_SetLight(p, 0x52, WEATHER_TASK_GetZoneFogE((int *)p));
    }
    return 1;
}
