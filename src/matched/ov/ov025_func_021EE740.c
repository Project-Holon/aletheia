/*
 * function: WEATHER_SNOW_Begin
 * address:  0x021EE740
 * packet:   pkt_ov025_021EE740
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WEATHER_SNOW_Begin  0x021EE740  thumb  ov025
 *   WEATHER_SNOW_SpawnParticles  0x021EEA34  thumb  ov025
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_SetupSpawner  0x021A21F8  thumb  ov021
 *   WEATHER_TASK_InitFog  0x021A22E0  thumb  ov021
 *   WEATHER_TASK_SaveCameraPos  0x021A2424  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
int *WEATHER_TASK_GetWorkBuffer(int *p);
void WEATHER_TASK_SetupSpawner(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
void WEATHER_TASK_InitFog(u32 *p, int a, int b, int c);
void WEATHER_TASK_SaveCameraPos(u8 *p);
void WEATHER_SNOW_SpawnParticles(int a, int n, int idx);

int WEATHER_SNOW_Begin(int a, int b)
{
    int *p = WEATHER_TASK_GetWorkBuffer((int *)a);

    WEATHER_TASK_SetupSpawner((u8 *)a, 1, 0x12, 1, 0x10, -3, 1, 0, (int)WEATHER_SNOW_SpawnParticles);
    p[1] = 0;
    p[2] = 0;
    WEATHER_TASK_InitFog((u32 *)a, 8, 0x7FDF, b);
    p[0] = 8;
    WEATHER_TASK_SaveCameraPos((u8 *)a);
    return 1;
}
