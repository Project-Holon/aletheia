/*
 * function: func_021F5368
 * address:  0x021F5368
 * packet:   pkt_021F5368
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F6264  0x021F6264  thumb  ov112
 */
#include "../include/Obj22538.h"

void func_021F6264(char *p, unsigned short v);

void func_021F5368(int *p, unsigned short v)
{
    func_021F6264(*(char * *)&((struct Obj22538 *)p)->f8, v);
}
