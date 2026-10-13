/*
 * function: FLD_TRADE_GetWantedGender
 * address:  0x021CC068
 * packet:   pkt_021CC060
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Follows the pointer at +0x8, then loads the 32-bit word at +0x60 of its target.
 */
#include "../include/Obj01219.h"
#include "../include/Obj18351.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FLD_TRADE_GetWantedGender(u8 *p)
{
    u8 *q = *(u8 * *)&((struct Obj01219 *)p)->f8;

    return ((struct Obj18351 *)q)->f60;
}

