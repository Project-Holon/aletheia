/*
 * function: func_02162358
 * address:  0x02162358
 * packet:   pkt_02162358
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

void func_02162358(int a0)
{
    int a1;
    int a2;
    int t4;

t4 = a0 + 0;
a0 = a0 + 0x28;
a1 = 0;
a2 = 8;
    a0 = func_02082BCC(a0, a1, a2);
loc_02162366:
a1 = ((struct Obj07202 *)t4)->f2;
a0 = 0x10;
a1 = a1 &~ a0;
((struct Obj07202 *)t4)->f2 = a1;
    return;}
