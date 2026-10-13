/*
 * function: WEATHER_SANDSTORM_Begin
 * address:  0x021EE740
 * packet:   pkt_ov027_021EE740
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_SetupSpawner  0x021A21F8  thumb  ov021
 *   WEATHER_TASK_InitFog  0x021A22E0  thumb  ov021
 *   WEATHER_TASK_SaveCameraPos  0x021A2424  thumb  ov021
 *   WEATHER_TASK_PlaySe  0x021A25BC  thumb  ov021
 *   WEATHER_SANDSTORM_SpawnParticles  0x021EEA04  thumb  ov027
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
int *WEATHER_TASK_GetWorkBuffer(int *p);
void WEATHER_TASK_SetupSpawner(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
void WEATHER_TASK_InitFog(u32 *p, int a, int b, int c);
void WEATHER_TASK_SaveCameraPos(u8 *p);
void WEATHER_TASK_PlaySe(unsigned char *o, int arg);
void WEATHER_SANDSTORM_SpawnParticles(int a, int b, int c);

int WEATHER_SANDSTORM_Begin(int a, int b)
{
    int *p = WEATHER_TASK_GetWorkBuffer((int *)a);

    WEATHER_TASK_SetupSpawner((u8 *)a, 1, 15, 1, 2, -2, 4, 1, (int)WEATHER_SANDSTORM_SpawnParticles);
    WEATHER_TASK_InitFog((u32 *)a, 8, 0x7fdf, b);
    p[0] = 1;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    WEATHER_TASK_SaveCameraPos((u8 *)a);
    WEATHER_TASK_PlaySe((unsigned char *)a, 0x6e3);
    return 1;
}
