/*
 * function: WEATHER_STORM_Begin
 * address:  0x021EEF58
 * packet:   pkt_ov026_021EEF58
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_STORM_Begin 0x021EEF58 thumb ov026
 *   WEATHER_STORM_SpawnParticles 0x021EF220 thumb ov026
 *   WEATHER_STORM_ResetThunderTimer 0x021EF93C thumb ov026
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_SetupSpawner 0x021A21F8 thumb ov021
 *   WEATHER_TASK_InitFog 0x021A22E0 thumb ov021
 *   WEATHER_TASK_SaveCameraPos 0x021A2424 thumb ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void WEATHER_TASK_SetupSpawner(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void WEATHER_TASK_InitFog(u32 *p, int a, int b, int c);
extern void WEATHER_TASK_SaveCameraPos(u8 *p);
typedef signed short   s16;
extern void WEATHER_STORM_ResetThunderTimer(s16 *p);
extern void WEATHER_STORM_SpawnParticles(int a, int n, int idx);

int WEATHER_STORM_Begin(int a, int b)
{
    int *p;

    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_SetupSpawner((u8 *)a, 1, 4, 1, 1, -4, 1, 1, (int)WEATHER_STORM_SpawnParticles);
    WEATHER_TASK_InitFog((u32 *)a, 9, 0x7FDF, b);
    WEATHER_TASK_SaveCameraPos((u8 *)a);
    WEATHER_STORM_ResetThunderTimer((s16 *)p);
    return 1;
}
