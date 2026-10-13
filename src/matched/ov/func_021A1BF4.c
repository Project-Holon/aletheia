/*
 * function: WEATHER_GetWeatherId
 * address:  0x021A1BF4
 * packet:   pkt_021A1780
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 16-bit halfword at +0xc of the object.
 */
#include "../include/Obj17998.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 WEATHER_GetWeatherId(u8 *p)
{
    return ((struct Obj17998 *)p)->fC;
}

