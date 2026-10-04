/*
 * function: func_02162438
 * address:  0x02162438
 * packet:   pkt_02162438
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215E2B8  0x0215E2B8  thumb  ov010
 */
#include "../include/Obj04155.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct R;
extern int func_0215E2B8(struct R *r, int a, int b, int n);

void func_02162438(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;

t4 = a0 + 0;
t5 = a1 + 0;
a3 = a2 + 0;
a1 = *(int *)&((struct Obj04155 *)t4)->f8;
a0 = a0 + 0x38;
a2 = t5 + 0;
    a0 = func_0215E2B8((struct R *)a0, a1, a2, a3);
loc_0216244A:
a0 = 1;
*(int *)&((struct Obj04155 *)t4)->f34 = a0;
    return;}
