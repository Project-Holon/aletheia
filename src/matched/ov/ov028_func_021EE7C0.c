/*
 * function: WEATHER_FOG_BeginPlainFixed
 * address: 0x021EE7C0
 * packet: pkt_ov028_021EE7C0
 * region: ov028
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_InitFog 0x021A22E0 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 *   WEATHER_TASK_SetLight 0x021A2114 thumb ov021
 */

typedef unsigned int u32;
typedef unsigned short u16;
extern int *WEATHER_TASK_GetWorkBuffer(int *);
extern void WEATHER_TASK_InitFog(u32 *, int, int, int);
extern u16 func_02014A10(u32);
extern int WEATHER_TASK_SetLight(u32 a, int b, u32 c);
int WEATHER_FOG_BeginPlainFixed(u32 *a, int b)
{
    int *p;
    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_InitFog(a, p[10], p[11], b);
    WEATHER_TASK_SetLight((u32)a, 62, func_02014A10(9));
    return 1;
}
