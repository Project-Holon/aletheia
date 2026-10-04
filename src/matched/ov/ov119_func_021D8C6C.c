/*
 * function: func_021D8C6C
 * address:  0x021D8C6C
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear the pending pointer and hand the object to the updater.
 *
 * symbols:
 *   func_021E66E8  0x021E66E8  thumb  ov119
 */
#include "../include/Obj04474.h"

extern void func_021E66E8(void *p);

void func_021D8C6C(void *p)
{
    if (((struct Obj04474 *)p)->fF60 != 0)
        ((struct Obj04474 *)p)->fF60 = 0;
    func_021E66E8(p);
}

