/*
 * function: EVENT_FIELD_PROCLINK_ClearReturnDefaultSlot
 * address:  0x021622F4
 * packet:   pkt_021622F4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 */
#include "../include/Obj07202.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02082BCC();

int EVENT_FIELD_PROCLINK_ClearReturnDefaultSlot(int a0, int a1, int a2)
{
    int t4;

t4 = a0 + 0;
a0 = a0 + 0x20;
a1 = 0;
a2 = 8;
    a0 = func_02082BCC(a0, a1, a2);
loc_02162302:
a1 = ((struct Obj07202 *)t4)->f2;
a0 = 8;
a1 = a1 &~ a0;
((struct Obj07202 *)t4)->f2 = a1;
    return a0;}
