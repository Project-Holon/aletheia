/*
 * function: ov208_func_021C47B4
 * address:  0x021C47B4
 * packet:   pkt_ov208_021C47B4
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: loads the object at +0x6ac of the second argument and
 * passes it to func_021BC6BC.  Pool word 0x021C47B5 in func_021C3B6C.
 *
 * symbols:
 *   func_021BC6BC  0x021BC6BC  thumb
 */
#include "../include/Obj25510.h"

extern void func_021BC6BC(char *p);

void ov208_func_021C47B4(int unused, char *p)
{
    func_021BC6BC(*(char * *)&((struct Obj25510 *)p)->f6AC);
}
