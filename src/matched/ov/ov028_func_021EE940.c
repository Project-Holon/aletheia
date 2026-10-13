/*
 * function: WEATHER_FOG_BeginKind14
 * address:  0x021EE940
 * packet:   pkt_ov028_021EE940
 * region:   ov028
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_GetCameraState  0x021A2148  thumb  ov021
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_InitFog  0x021A22E0  thumb  ov021
 *   gFogSlopeByCameraState     0x021EEA80  data  ov028  a1
 *   gFogOffsetByCameraState     0x021EEAA4  data  ov028  a4
 */

typedef unsigned int   u32;
int WEATHER_TASK_GetCameraState(unsigned char *o);
int *WEATHER_TASK_GetWorkBuffer(int *p);
void WEATHER_TASK_InitFog(u32 *p, int a, int b, int c);
extern unsigned char gFogSlopeByCameraState[];
extern int gFogOffsetByCameraState[];

int WEATHER_FOG_BeginKind14(int a, int b)
{
    int i = WEATHER_TASK_GetCameraState((unsigned char *)a);
    int *p = WEATHER_TASK_GetWorkBuffer((int *)a);

    p[1] = 0;
    p[0] = 14;
    p[11] = gFogSlopeByCameraState[i];
    p[12] = gFogOffsetByCameraState[i];
    WEATHER_TASK_InitFog((u32 *)a, p[11], 0x7fdf, b);
    return 1;
}
