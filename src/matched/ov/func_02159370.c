/*
 * function: func_02159370
 * address:  0x02159370
 * packet:   pkt_02159370
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215932C  0x0215932C  thumb  ov010
 */
#include "../include/Obj05851.h"
#include "../include/Obj12031.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215932C();

int func_02159370(int a0, int a1, int a2, int a3)
{
    int t4;

t4 = a0 + 0;
a1 = ((struct Obj05851 *)t4)->f14;
a3 = ((struct Obj05851 *)t4)->f1C;
a0 = ((struct Obj12031 *)((char *)a1))->f0;
a2 = a1 + 1;
((struct Obj05851 *)t4)->f14 = a2;
a0 = a0 << 2;
a0 = *(int *)((char *)a3 + a0);
a1 = ((struct Obj12031 *)a1)->f1;
a0 = a0 << 0x18;
a2 = a2 + 1;
a0 = (unsigned)a0 >> 0x18;
((struct Obj05851 *)t4)->f14 = a2;
    a0 = func_0215932C(a0, a1, a2, a3);
loc_02159390:
((struct Obj05851 *)t4)->fE = a0;
a0 = 0;
    return a0;}
