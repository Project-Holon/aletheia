/*
 * function: WEATHER_STORM_StartCalm
 * address:  0x021EF614
 * packet:   pkt_ov026_021EF614
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   WEATHER_TASK_ChangeFog  0x021A232C  thumb  ov021
 *   WEATHER_TASK_SetBillboardVisible  0x021A2160  thumb  ov021
 *   WEATHER_TASK_PlaySe  0x021A25BC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020056EC(u32 v);
extern void WEATHER_TASK_ChangeFog(u8 *p, int a, int b, int c, int d);
extern void WEATHER_TASK_SetBillboardVisible(unsigned char *o, unsigned int v, int i);
extern void WEATHER_TASK_PlaySe(unsigned char *o, int arg);

void WEATHER_STORM_StartCalm(int a, u16 *p, int c, int d)
{
    u32 r = func_020056EC(0);
    p[8] = 1;
    p[7] = r % 400 + 0x3C;
    p[6] = 0;
    if (d == 0) {
        WEATHER_TASK_ChangeFog((u8 *)a, 9, 0x7F80, 10, c);
        WEATHER_TASK_SetBillboardVisible((unsigned char *)a, 0, 1);
        WEATHER_TASK_PlaySe((unsigned char *)a, 0x690);
    }
}
