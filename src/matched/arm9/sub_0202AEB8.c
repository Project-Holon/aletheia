/*
 * unit:     no
 * function: ISS_CITY_SYS_SetVolume
 * address:  0x0202AEB8
 * packet:   pkt_0202AC60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A plain word setter at offset 0xc. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_SYS_SetVolume.c \
 *       --func ISS_CITY_SYS_SetVolume --addr 0x0202AEB8 --cc 1.1p1 --thumb
 */
#include "../include/Obj16761.h"

typedef unsigned int u32;

void ISS_CITY_SYS_SetVolume(void *obj, u32 value)
{
    ((struct Obj16761 *)obj)->fC = value;
}
