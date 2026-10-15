/*
 * function: GFL_NET_SAVE_SetStep
 * address:  0x02010888
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores the value at the object's +8 field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SAVE_SetStep.c \
 *       --func GFL_NET_SAVE_SetStep --addr 0x02010888 --thumb --cc 1.1p1
 */
#include "../include/Obj15612.h"

typedef unsigned char u8;
typedef unsigned int  u32;

void GFL_NET_SAVE_SetStep(u8 *p, u32 v)
{
    ((struct Obj15612 *)p)->f8 = v;
}
