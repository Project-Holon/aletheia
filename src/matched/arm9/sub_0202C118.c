/*
 * unit:     no
 * function: ISS_SWITCH_SYS_Init
 * address:  0x0202C118
 * packet:   pkt_0202BDE8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A constructor-shaped clear: a word, a byte one past it, and two more
 * words. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_Init.c \
 *       --func ISS_SWITCH_SYS_Init --addr 0x0202C118 --cc 1.1p1 --thumb
 */
#include "../include/Obj04107.h"

typedef unsigned char u8;
typedef unsigned int u32;

void ISS_SWITCH_SYS_Init(void *obj)
{
    ((struct Obj04107 *)obj)->f0 = 0;
    ((struct Obj04107 *)obj)->f4 = 0;
    ((struct Obj04107 *)obj)->f8 = 0;
    ((struct Obj04107 *)obj)->fC = 0;
}
