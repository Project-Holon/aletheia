/*
 * function: func_021DA384
 * address:  0x021DA384
 * packet:   pkt_021DA384
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Leaf: clears the word at +0x154.
 */
#include "../include/Obj24329.h"

typedef unsigned long u32;

void func_021DA384(char *obj)
{
    ((struct Obj24329 *)obj)->f154 = 0;
}
