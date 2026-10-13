/*
 * function: ISS_SYS_UpdateCity
 * address:  0x0202B6DC
 * packet:   pkt_0202B6CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Blocked: 0202AB38 (thumb, from header) has no witness outside 0202B6DC..0202B6EC. Every concrete byte reproduces.
 * status:   EXACT
 * closed:   blocker ISS_SYS_UpdateCity.c is now a manifest entry (matched class)
 * symbols:
 *   ISS_CITY_SYS_Update  0x0202AB38  thumb
 *
 */
#include "../include/Obj02010.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void ISS_CITY_SYS_Update(u8 *p);

void ISS_SYS_UpdateCity(u8 *o)
{
    if ((((struct Obj02010 *)o)->fC & 1) == 0) {
        ISS_CITY_SYS_Update((u8 *)(((struct Obj02010 *)o)->f10));
    }
}
