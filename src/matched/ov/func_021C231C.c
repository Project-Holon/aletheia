/*
 * function: func_021C231C
 * address:  0x021C231C
 * packet:   pkt_021C231C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC518 0x021BC518  thumb  ov208
 *
 * Loads the word at +0x418 and tail-calls func_021BC518 with it.
 */
#include "../include/Obj18287.h"

extern void func_021BC518(int *p);

void func_021C231C(char *p)
{
    func_021BC518((int *)(((struct Obj18287 *)p)->f418));
}
