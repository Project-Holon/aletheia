/*
 * function: WEATHER_STORM_EndFinish
 * address: 0x021EF1D4
 * packet: pkt_ov026_021EF1D4
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_DisableFog 0x021A231C thumb ov021
 *   WEATHER_TASK_ResetLight 0x021A2120 thumb ov021
 */

typedef unsigned int u32;
extern int *WEATHER_TASK_GetWorkBuffer(int *);
extern void WEATHER_TASK_DisableFog(u32 *, int);
extern void WEATHER_TASK_ResetLight(u32 *, int);
int WEATHER_STORM_EndFinish(u32 *a, int b)
{
    WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_DisableFog(a, b);
    WEATHER_TASK_ResetLight(a, b);
    return 1;
}
