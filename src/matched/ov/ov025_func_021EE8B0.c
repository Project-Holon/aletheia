/*
 * function: WEATHER_SNOW_EndParticles
 * address: 0x021EE8B0
 * packet: pkt_ov025_021EE8B0
 * region: ov025
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_RetargetSpawner 0x021A2228 thumb ov021
 *   WEATHER_TASK_GetCameraScroll 0x021A244C thumb ov021
 *   WEATHER_TASK_ShiftParticles 0x021A2564 thumb ov021
 */
typedef unsigned char u8;
typedef struct { char pad[0x774]; int *list; } Obj;
extern int *WEATHER_TASK_GetWorkBuffer(int *);
extern void WEATHER_TASK_RetargetSpawner(u8 *, int, int, int, int);
extern void WEATHER_TASK_GetCameraScroll(u8 *, int *, int *);
extern void WEATHER_TASK_ShiftParticles(Obj *, int, int);
int WEATHER_SNOW_EndParticles(u8 *a)
{
    int *p;
    int x;
    int y;
    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_RetargetSpawner(a, 0, 18, 3, -1);
    *p = 16;
    WEATHER_TASK_GetCameraScroll(a, &x, &y);
    WEATHER_TASK_ShiftParticles((Obj *)a, x, y);
    return 1;
}
