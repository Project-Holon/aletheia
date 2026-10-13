/*
 * function: WEATHER_DOWNPOUR_Run
 * address: 0x021EF0D0
 * packet: pkt_ov025_021EF0D0
 * region: ov025
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_StepSpawnTimer 0x021A2248 thumb ov021
 *   WEATHER_TASK_GetCameraScroll 0x021A244C thumb ov021
 *   WEATHER_TASK_ShiftParticles 0x021A2564 thumb ov021
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int *WEATHER_TASK_GetWorkBuffer(int *);
extern int WEATHER_TASK_StepSpawnTimer(u8 *, int);
extern void WEATHER_TASK_GetCameraScroll(u8 *, int *, int *);
typedef struct { char pad[0x774]; int *list; } Obj;
extern void WEATHER_TASK_ShiftParticles(Obj *, int, int);

int WEATHER_DOWNPOUR_Run(u8 *a, int b, int c)
{
    int x;
    int y;
    WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_StepSpawnTimer(a, c);
    WEATHER_TASK_GetCameraScroll(a, &x, &y);
    WEATHER_TASK_ShiftParticles((Obj *)a, x, y);
    return 0;
}
