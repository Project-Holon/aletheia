/*
 * unit:     no
 * function: ISS_CITY_SYS_IsEnabled
 * address:  0x0202ACC8
 * packet:   pkt_0202AC60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A plain word getter at offset 4. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_SYS_IsEnabled.c \
 *       --func ISS_CITY_SYS_IsEnabled --addr 0x0202ACC8 --cc 1.1p1 --thumb
 */
#include "../include/Obj16757.h"

typedef unsigned int u32;

u32 ISS_CITY_SYS_IsEnabled(void *obj)
{
    return ((struct Obj16757 *)obj)->f4;
}
