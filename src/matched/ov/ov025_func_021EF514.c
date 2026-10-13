/*
 * function: WEATHER_DIAMOND_DUST_EndParticles
 * address: 0x021EF514
 * packet: pkt_ov025_021EF514
 * region: ov025
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_RetargetSpawner 0x021A2228 thumb ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int *WEATHER_TASK_GetWorkBuffer(int *);
extern void WEATHER_TASK_RetargetSpawner(u8 *, int, int, int, int);

int WEATHER_DIAMOND_DUST_EndParticles(u8 *a)
{
    int *p;
    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_RetargetSpawner(a, 0, 16, 2, -2);
    *p = 100;
    return 1;
}
