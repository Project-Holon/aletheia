/*
 * function: WEATHER_THUNDERSTORM_BeginPlain
 * address:  0x021EEC5C
 * packet:   pkt_ov026_021EEC5C
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_THUNDERSTORM_BeginPlain 0x021EEC5C thumb ov026
 *   WEATHER_THUNDERSTORM_SpawnParticles 0x021EEE38 thumb ov026
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_SetupSpawner 0x021A21F8 thumb ov021
 *   WEATHER_TASK_InitFog 0x021A22E0 thumb ov021
 *   WEATHER_TASK_PrewarmParticles 0x021A2254 thumb ov021
 *   WEATHER_TASK_PlaySe 0x021A25BC thumb ov021
 *   WEATHER_TASK_SetLight 0x021A2114 thumb ov021
 *   WEATHER_TASK_SetBillboardVisible 0x021A2160 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void WEATHER_TASK_SetupSpawner(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void WEATHER_TASK_InitFog(u32 *p, int a, int b, int c);
extern void WEATHER_TASK_PrewarmParticles(u8 *p, void (*fn)(u8 *, int, u32), int n, int m, int k, u16 w);
extern void WEATHER_TASK_PlaySe(unsigned char *o, int arg);
extern int WEATHER_TASK_SetLight(u32 a, int b, u32 c);
extern void WEATHER_TASK_SetBillboardVisible(unsigned char *o, unsigned int v, int i);
extern u16 func_02014A10(u32 i);
extern void WEATHER_THUNDERSTORM_SpawnParticles(int a, int n, int idx);

int WEATHER_THUNDERSTORM_BeginPlain(int a, int b, u16 c)
{
    WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_SetupSpawner((u8 *)a, 2, 0, 2, 0, -3, 1, 1, (int)WEATHER_THUNDERSTORM_SpawnParticles);
    WEATHER_TASK_InitFog((u32 *)a, 9, 0x7F80, b);
    WEATHER_TASK_PrewarmParticles((u8 *)a, (void (*)(u8 *, int,  u32))WEATHER_THUNDERSTORM_SpawnParticles, 0x14, 5, 1, c);
    WEATHER_TASK_PlaySe((unsigned char *)a, 0x690);
    WEATHER_TASK_SetLight(a, 0x3E, func_02014A10(6));
    WEATHER_TASK_SetBillboardVisible((unsigned char *)a, 1, 0);
    return 1;
}
