/*
 * function: WEATHER_THUNDERSTORM_EndParticles
 * address: 0x021EED10
 * packet: pkt_ov026_021EED10
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_RetargetSpawner 0x021A2228 thumb ov021
 *   WEATHER_TASK_StopSe 0x021A25CC thumb ov021
 *   WEATHER_TASK_SetBillboardVisible 0x021A2160 thumb ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int *WEATHER_TASK_GetWorkBuffer(int *);
extern void WEATHER_TASK_RetargetSpawner(u8 *, int, int, int, int);
extern void WEATHER_TASK_StopSe(u8 *);
extern void WEATHER_TASK_SetBillboardVisible(u8 *, u32, int);

int WEATHER_THUNDERSTORM_EndParticles(u8 *a)
{
    int *p;
    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_RetargetSpawner(a, 0, 15, 3, -1);
    ((unsigned short *)p)[1] = 1;
    WEATHER_TASK_StopSe(a);
    WEATHER_TASK_SetBillboardVisible(a, 0, 0);
    return 1;
}
