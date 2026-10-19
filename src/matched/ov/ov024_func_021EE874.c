/*
 * function: WEATHER_CLEAR_EndFinish
 * address:  0x021EE874
 * packet:   pkt_ov024_021EE874
 * region:   ov024
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WEATHER_CLEAR_EndFinish  0x021EE874  thumb  ov024
 *   WEATHER_TASK_IsZoneFog  0x021A23E8  thumb  ov021
 *   WEATHER_TASK_DisableFog  0x021A231C  thumb  ov021
 *   WEATHER_TASK_IsZoneFogLight  0x021A23F4  thumb  ov021
 *   WEATHER_TASK_ResetLight  0x021A2120  thumb  ov021
 */

typedef unsigned int   u32;
int WEATHER_TASK_IsZoneFog(int *p);
void WEATHER_TASK_DisableFog(u32 *p, int x);
int WEATHER_TASK_IsZoneFogLight(int *p);
void WEATHER_TASK_ResetLight(u32 *p, int x);

int WEATHER_CLEAR_EndFinish(int a0, int a1)
{
    if (WEATHER_TASK_IsZoneFog((int *)a0)) {
        WEATHER_TASK_DisableFog((u32 *)a0, a1);
    }
    if (WEATHER_TASK_IsZoneFogLight((int *)a0)) {
        WEATHER_TASK_ResetLight((u32 *)a0, a1);
    }
    return 1;
}
