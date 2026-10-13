/*
 * function: FIELDMAP_GetTimeZone
 * address:  0x02189A38
 * packet:   pkt_02189A38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   TIMEZONE_GetNowTimeZone  0x020113D8  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17890.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 TIMEZONE_GetNowTimeZone(u32);
struct BigObj;
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);

int FIELDMAP_GetTimeZone(int a)
{
return TIMEZONE_GetNowTimeZone(GAME_DATA_GetSeason((const struct BigObj *)(((struct Obj17890 *)((u8 *)(a)))->f8)));
}

