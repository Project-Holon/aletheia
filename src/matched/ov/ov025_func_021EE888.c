/*
 * function: WEATHER_SNOW_Run
 * address: 0x021EE888
 * packet: pkt_ov025_021EE888
 * region: ov025
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding at 0x021EE8AE.
 * symbols:
 *   WEATHER_TASK_StepSpawnTimer 0x021A2248 thumb ov021
 *   WEATHER_TASK_GetCameraScroll 0x021A244C thumb ov021
 *   WEATHER_TASK_ShiftParticles 0x021A2564 thumb ov021
 */
typedef unsigned char u8;
typedef struct { char pad[0x774]; int *list; } Obj;
extern int WEATHER_TASK_StepSpawnTimer(u8 *, int);
extern void WEATHER_TASK_GetCameraScroll(u8 *, int *, int *);
extern void WEATHER_TASK_ShiftParticles(Obj *, int, int);
int WEATHER_SNOW_Run(u8 *p, int unused, int arg)
{
    int x;
    int y;
    WEATHER_TASK_StepSpawnTimer(p, arg);
    WEATHER_TASK_GetCameraScroll(p, &x, &y);
    WEATHER_TASK_ShiftParticles((Obj *)p, x, y);
    return 0;
}
