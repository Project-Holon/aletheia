/*
 * function: WEATHER_FOG_EndFinish
 * address:  0x021EEA64
 * packet:   pkt_021EEA64
 * region:   ov028
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_DisableFog  0x021A231C  thumb  ov021
 *   WEATHER_TASK_ResetLight  0x021A2120  thumb  ov021
 */

typedef unsigned int   u32;
void WEATHER_TASK_DisableFog(u32 *p, int x);
void WEATHER_TASK_ResetLight(u32 *p, int x);

int WEATHER_FOG_EndFinish(int a0, int a1)
{
    WEATHER_TASK_DisableFog((u32 *)a0, a1);
    WEATHER_TASK_ResetLight((u32 *)a0, a1);
    return 1;
}
