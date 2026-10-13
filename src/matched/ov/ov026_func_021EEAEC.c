/*
 * function: WEATHER_THUNDERSTORM_Begin
 * address:  0x021EEAEC
 * packet:   pkt_ov026_021EEAEC
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_THUNDERSTORM_Begin 0x021EEAEC thumb ov026
 *   WEATHER_THUNDERSTORM_SpawnParticles 0x021EEE38 thumb ov026
 *   WEATHER_LIGHTNING_Init 0x021EF9B0 thumb ov026
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_SetupSpawner 0x021A21F8 thumb ov021
 *   WEATHER_TASK_InitFog 0x021A22E0 thumb ov021
 *   WEATHER_TASK_SaveCameraPos 0x021A2424 thumb ov021
 */

typedef signed short s16;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void WEATHER_LIGHTNING_Init(u8 *p, int b);
extern void WEATHER_TASK_SetupSpawner(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void WEATHER_TASK_InitFog(u32 *p, int a, int b, int c);
extern void WEATHER_TASK_SaveCameraPos(u8 *p);
extern void WEATHER_THUNDERSTORM_SpawnParticles(int a, int n, int idx);

int WEATHER_THUNDERSTORM_Begin(int a, int b)
{
    s16 *p;

    p = (s16 *)WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_LIGHTNING_Init((u8 *)(p + 6), 2);
    WEATHER_TASK_SetupSpawner((u8 *)a, 1, 0xF, 2, 0, -3, 1, 1, (int)WEATHER_THUNDERSTORM_SpawnParticles);
    WEATHER_TASK_InitFog((u32 *)a, 9, 0x7FDF, b);
    p[1] = 0;
    p[0] = 0;
    WEATHER_TASK_SaveCameraPos((u8 *)a);
    return 1;
}
