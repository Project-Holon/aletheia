/*
 * unit:     no
 * function: ISS_CITY_SYS_GetFadeLevel
 * address:  0x0202AE04
 * packet:   pkt_0202AC60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A plain word getter at offset 0x10. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_SYS_GetFadeLevel.c \
 *       --func ISS_CITY_SYS_GetFadeLevel --addr 0x0202AE04 --cc 1.1p1 --thumb
 */
#include "../include/Obj16760.h"

typedef unsigned int u32;

u32 ISS_CITY_SYS_GetFadeLevel(void *obj)
{
    return ((struct Obj16760 *)obj)->f10;
}
