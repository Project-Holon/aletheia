/*
 * function: SWEET_SCENT_CheckWeatherClear
 * address:  0x021C61D4
 * packet:   pkt_021C61D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELDMAP_GetWeather  0x02188C6C  thumb  ov021
 *   WEATHER_GetWeatherId  0x021A1BF4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18307.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELDMAP_GetWeather(u8 *p);
extern u16 WEATHER_GetWeatherId(u8 *p);

int SWEET_SCENT_CheckWeatherClear(u32 a)
{
if (WEATHER_GetWeatherId((u8 *)FIELDMAP_GetWeather((u8 *)(((struct Obj18307 *)((u8 *)(a)))->fC))) == 0) {
    return 1;
}
return 0;
}

