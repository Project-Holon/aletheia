/*
 * function: SODATEYA_RollPersonalRnd
 * address:  0x021C4024
 * packet:   pkt_021C4024
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   SODATEYA_RollRandomU32  0x021C4078  thumb
 */
#include "../include/Obj20194.h"

typedef unsigned int u32;

u32 SODATEYA_RollRandomU32(void);

void SODATEYA_RollPersonalRnd(int a, char *p)
{
    ((struct Obj20194 *)p)->f34 = SODATEYA_RollRandomU32();
}
