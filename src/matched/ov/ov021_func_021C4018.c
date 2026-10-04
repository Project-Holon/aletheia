/*
 * function: func_021C4018
 * address:  0x021C4018
 * packet:   pkt_021C4018
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02008530  0x02008530  thumb
 */
#include "../include/Obj20193.h"

typedef unsigned int u32;

u32 func_02008530(void);

void func_021C4018(int a, char *p)
{
    ((struct Obj20193 *)p)->f30 = func_02008530();
}
