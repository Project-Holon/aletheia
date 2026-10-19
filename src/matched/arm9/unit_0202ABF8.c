/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202ABF8
 * packet:   pkt_0202A188
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ISS_CITY_SYS_GetMode, ISS_CITY_SYS_SetMode
 *
 * A getter/setter pair on a word field at offset 8 of the same object, back
 * to back with no gap. Neither function has a relocation.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202ABF8.c \
 *       --addr 0x0202ABF8 --thumb
 */
#include "../include/Obj17262.h"
#include "../include/Obj17263.h"

typedef unsigned int u32;

u32 ISS_CITY_SYS_GetMode(void *obj)
{
    return ((struct Obj17262 *)obj)->f8;
}

void ISS_CITY_SYS_SetMode(void *obj, u32 value)
{
    ((struct Obj17263 *)obj)->f8 = value;
}
