/*
 * function: func_021DC9B8
 * address:  0x021DC9B8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DC9A0  0x021DC9A0  thumb  ov170
 *
 * Re-run the reset helper with the stored word.
 */
#include "../include/Obj05868.h"

extern void func_021DC9A0(char *, int);

void func_021DC9B8(char *p)
{
    func_021DC9A0(p, ((struct Obj05868 *)p)->f5C);
}

