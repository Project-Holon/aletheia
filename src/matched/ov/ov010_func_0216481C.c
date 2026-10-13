/*
 * function: CALENDER_GetWeather
 * address: 0x0216481C
 * packet: pkt_ov010_0216481C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_CLOCK_GetMonth 0x021690D0 thumb ov010
 *   FIELD_CLOCK_GetDay 0x021690E0 thumb ov010
 *   CALENDER_GetWeatherOnDate 0x02164844 thumb ov010
 */
#include "../include/Obj12360.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int FIELD_CLOCK_GetMonth(int a0);
extern int FIELD_CLOCK_GetDay(int a0);
extern u8 CALENDER_GetWeatherOnDate(u8 *,u32,u8,u8);
u8 CALENDER_GetWeather(u8 *p,u32 b){int c=FIELD_CLOCK_GetMonth((int)(((struct Obj12360 *)p)->f4));int d=FIELD_CLOCK_GetDay((int)(((struct Obj12360 *)p)->f4));return CALENDER_GetWeatherOnDate(p,b,c,d);}
