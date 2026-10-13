/*
 * function: WEATHER_BLIZZARD_EndParticles
 * address: 0x021EECB0
 * packet: pkt_ov025_021EECB0
 * region: ov025
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_RetargetSpawner 0x021A2228 thumb ov021
 *   WEATHER_BLIZZARD_ScrollFogLayer 0x021EEEE0 thumb ov025
 *   WEATHER_TASK_SetBillboardVisible 0x021A2160 thumb ov021
 *   WEATHER_TASK_StopSe 0x021A25CC thumb ov021
 */
typedef unsigned char u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *);
extern void WEATHER_TASK_RetargetSpawner(u8 *, int, int, int, int);
extern void WEATHER_BLIZZARD_ScrollFogLayer(int, int *);
extern void WEATHER_TASK_SetBillboardVisible(u8 *, unsigned int, int);
extern void WEATHER_TASK_StopSe(u8 *);
int WEATHER_BLIZZARD_EndParticles(u8 *a)
{
    int *p;
    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_RetargetSpawner(a, 0, 3, 1, -1);
    *p = 10;
    WEATHER_BLIZZARD_ScrollFogLayer((int)a, p);
    WEATHER_TASK_SetBillboardVisible(a, 0, 0);
    WEATHER_TASK_StopSe(a);
    return 1;
}
