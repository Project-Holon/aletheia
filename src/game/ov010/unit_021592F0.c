/*
 * file:     unit_021592F0.c
 * function: func_021592F0
 * address:  0x021592F0
 * packet:   pkt_021592F0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 */
#include "../../matched/include/Obj09154.h"
#include "../../matched/include/Obj17643.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0201134C();

int func_021592F0(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a0 + 0;
a1 = ((struct Obj09154 *)t5)->f14;
t4 = ((struct Obj17643 *)((char *)a1))->f0;
a1 = a1 + 1;
((struct Obj09154 *)t5)->f14 = a1;
    a0 = func_0201134C(a0, a1);
loc_02159300:
a2 = ((struct Obj09154 *)t5)->f1C;
a1 = t4 << 2;
*(int *)((char *)a2 + a1) = a0;
a0 = 0;
    return a0;}
