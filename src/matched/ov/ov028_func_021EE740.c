/*
 * function: func_021EE740
 * address: 0x021EE740
 * packet: pkt_ov028_021EE740
 * region: ov028
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_InitFog 0x021A22E0 thumb ov021
 */

typedef unsigned int u32;
extern int *WEATHER_TASK_GetWorkBuffer(int *);
extern void WEATHER_TASK_InitFog(u32 *, int, int, int);
int func_021EE740(u32 *a, int b)
{
    int *p;
    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_InitFog(a, 9, 0x7FDF, b);
    p[0] = 0;
    p[10] = 9;
    p[11] = 0x7F78;
    return 1;
}
