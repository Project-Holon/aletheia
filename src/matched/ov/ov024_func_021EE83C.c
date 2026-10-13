/*
 * function: func_021EE83C
 * address:  0x021EE83C
 * packet:   pkt_ov024_021EE83C
 * region:   ov024
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021EE83C  0x021EE83C  thumb  ov024
 *   WEATHER_TASK_CheckZoneFogA  0x021A23E8  thumb  ov021
 *   WEATHER_TASK_ChangeFogOffset  0x021A2390  thumb  ov021
 */

typedef unsigned int u32;
int WEATHER_TASK_CheckZoneFogA(int *p);
void WEATHER_TASK_ChangeFogOffset(u32 *p, int a, int b, int c);

int func_021EE83C(int p, int v)
{
    if (WEATHER_TASK_CheckZoneFogA((int *)p)) {
        WEATHER_TASK_ChangeFogOffset((u32 *)p, 0x7FFF, 0x50, v);
    }
    return 1;
}
