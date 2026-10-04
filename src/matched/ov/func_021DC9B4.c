/*
 * function: func_021DC9B4
 * address:  0x021DC9B4
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Store the second argument into the word field at +0x5c of the object.
 */
#include "../include/Obj18438.h"

void func_021DC9B4(char *p, int v)
{
    ((struct Obj18438 *)p)->f5C = v;
}
