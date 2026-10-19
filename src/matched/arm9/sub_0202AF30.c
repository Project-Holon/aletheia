/*
 * unit:     no
 * function: ISS_CITY_UNIT_GetZoneId
 * address:  0x0202AF30
 * packet:   pkt_0202AC60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A plain halfword getter at offset 0. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_UNIT_GetZoneId.c \
 *       --func ISS_CITY_UNIT_GetZoneId --addr 0x0202AF30 --cc 1.1p1 --thumb
 */
#include "../include/Obj16762.h"

typedef unsigned short u16;
typedef unsigned int u32;

u32 ISS_CITY_UNIT_GetZoneId(void *obj)
{
    return ((struct Obj16762 *)obj)->f0;
}
