/*
 * function: SODATEYA_SetOtId
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

struct Sub0200852CObj;
u32 func_02008530(const struct Sub0200852CObj *obj);

void SODATEYA_SetOtId(int a, char *p)
{
    ((struct Obj20193 *)p)->f30 = func_02008530((const struct Sub0200852CObj *)a);
}
