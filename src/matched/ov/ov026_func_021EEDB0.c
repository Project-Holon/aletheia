/*
 * function: WEATHER_THUNDERSTORM_EndFinish
 * address: 0x021EEDB0
 * packet: pkt_ov026_021EEDB0
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_DisableFog 0x021A231C thumb ov021
 *   WEATHER_TASK_ResetLight 0x021A2120 thumb ov021
 *   WEATHER_LIGHTNING_Clear 0x021EF9CC thumb ov026
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int *WEATHER_TASK_GetWorkBuffer(int *);
extern void WEATHER_TASK_DisableFog(u32 *, int);
extern void WEATHER_TASK_ResetLight(u32 *, int);
extern void WEATHER_LIGHTNING_Clear(int);

int WEATHER_THUNDERSTORM_EndFinish(u8 *a, int b)
{
    int *p;
    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_DisableFog((u32 *)a, b);
    WEATHER_TASK_ResetLight((u32 *)a, b);
    WEATHER_LIGHTNING_Clear((int)(p + 3));
    return 1;
}
