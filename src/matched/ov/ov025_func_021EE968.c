/*
 * function: WEATHER_SNOW_EndFinish
 * address: 0x021EE968
 * packet: pkt_ov025_021EE968
 * region: ov025
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding at 0x021EE97E.
 * symbols:
 *   WEATHER_TASK_DisableFog 0x021A231C thumb ov021
 *   WEATHER_TASK_ResetLight 0x021A2120 thumb ov021
 */
typedef unsigned int u32;
extern void WEATHER_TASK_DisableFog(u32 *, int);
extern void WEATHER_TASK_ResetLight(u32 *, int);
int WEATHER_SNOW_EndFinish(u32 *p, int x)
{
    WEATHER_TASK_DisableFog(p, x);
    WEATHER_TASK_ResetLight(p, x);
    return 1;
}
