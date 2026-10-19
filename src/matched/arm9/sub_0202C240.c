/*
 * unit:     no
 * function: ISS_SWITCH_SYS_GetSetCount
 * address:  0x0202C240
 * packet:   pkt_0202BDE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A plain byte getter at offset 4. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_GetSetCount.c \
 *       --func ISS_SWITCH_SYS_GetSetCount --addr 0x0202C240 --cc 1.1p1 --thumb
 */
#include "../include/Obj16765.h"

typedef unsigned char u8;
typedef unsigned int u32;

u32 ISS_SWITCH_SYS_GetSetCount(void *obj)
{
    return ((struct Obj16765 *)obj)->f4;
}
