/*
 * function: func_0216D5E0
 * address:  0x0216D5E0
 * packet:   pkt_0216D5E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D55C  0x0216D55C  thumb  ov010
 */
#include "../include/Obj00113.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D55C(int a0, int a1);

void func_0216D5E0(int a0, int a1)
{
    int t4;
    int t5;

t4 = a1 + 0;
a1 = 8;
t5 = a0 + 0;
    a0 = func_0216D55C(a0, a1);
loc_0216D5EC:
    if (a0 != 0) goto loc_0216D5F6;
loc_0216D5F0:
a0 = ((struct Obj00113 *)t5)->f18;
((struct Obj00113 *)t5)->f1C = a0;
((struct Obj00113 *)t5)->f18 = t4;
loc_0216D5F6:
    return;}
