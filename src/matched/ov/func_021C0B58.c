/*
 * function: func_021C0B58
 * address:  0x021C0B58
 * packet:   pkt_021C0B58
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none)
 *
 * Calls 0x0204AFD8 on +0x58 and 0x0204ADA4 on +0x54 of the second argument.
 */
#include "../include/Obj12127.h"

typedef unsigned int   u32;
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);

void func_021C0B58(void *a, char *q)
{
    func_0204AFD8(((struct Obj12127 *)q)->f58);
    func_0204ADA4(((struct Obj12127 *)q)->f54);
}
