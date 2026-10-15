/*
 * function: WEATHER_DOWNPOUR_BeginParticles
 * address:  0x021EEFF0
 * packet:   pkt_ov025_021EEFF0
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_DOWNPOUR_BeginParticles 0x021EEFF0 thumb ov025
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_StepSpawner 0x021A223C thumb ov021
 *   WEATHER_TASK_ChangeFog 0x021A232C thumb ov021
 *   WEATHER_TASK_FadeLight 0x021A2108 thumb ov021
 *   WEATHER_TASK_IsFogIdle 0x021A23B0 thumb ov021
 *   WEATHER_TASK_GetCameraScroll 0x021A244C thumb ov021
 *   WEATHER_TASK_ShiftParticles 0x021A2564 thumb ov021
 *   ZONEDATA_GetLightTableMember 0x02014A10 thumb
 */

typedef signed int     s32;
typedef unsigned char  u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern int WEATHER_TASK_StepSpawner(unsigned char *o, int arg);
extern void WEATHER_TASK_ChangeFog(u8 *p, int a, int b, int c, int d);
extern int WEATHER_TASK_FadeLight(unsigned int a, int b, int c);
extern int WEATHER_TASK_IsFogIdle(unsigned int a);
extern void WEATHER_TASK_GetCameraScroll(u8 *o, s32 *outX, s32 *outY);
extern void WEATHER_TASK_ShiftParticles(int, int, int);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 ZONEDATA_GetLightTableMember(u32 i);

int WEATHER_DOWNPOUR_BeginParticles(int a, int b, int c)
{
    int *p;
    int t;
    int x;
    int y;

    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    t = WEATHER_TASK_StepSpawner((unsigned char *)a, c);
    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            WEATHER_TASK_ChangeFog((u8 *)a, 9, 0x7F80, 0x3C, b);
            WEATHER_TASK_FadeLight(a, 0x3E, ZONEDATA_GetLightTableMember(5));
        }
    } else if (WEATHER_TASK_IsFogIdle(a) != 0 && t != 0) {
        return 1;
    }
    WEATHER_TASK_GetCameraScroll((u8 *)a, &x, &y);
    WEATHER_TASK_ShiftParticles(a, x, y);
    return 0;
}
