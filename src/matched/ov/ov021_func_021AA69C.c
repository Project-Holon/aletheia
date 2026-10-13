/*
 * function: FIELD_ENCOUNT_GetBattleWeather
 * address:  0x021AA69C
 * packet:   pkt_ov021_021AA69C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   FIELDMAP_GetWeather  0x02188C6C  thumb
 *   WEATHER_GetWeatherId  0x021A1BF4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 FIELDMAP_GetWeather(u8 *p);
extern u16 WEATHER_GetWeatherId(u8 *p);

u8 FIELD_ENCOUNT_GetBattleWeather(void *p)
{
    switch (WEATHER_GetWeatherId((u8 *)FIELDMAP_GetWeather(p))) {
    case 2:
    case 6:
    case 7:
        return 2;
    case 3:
    case 12:
        return 4;
    case 4:
    case 5:
        return 3;
    }
    return 0;
}
