/*
 * function: func_0215AA34
 * address:  0x0215AA34
 * packet:   pkt_0215AA34
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021590D4  0x021590D4  thumb  ov010
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern int func_021590D4();

int func_0215AA34(int a0, int a1)
{
    int t4;
    void *v0;

t4 = a0 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215AA3C:
a1 = *(int *)&((struct Obj00005 *)t4)->f1C;
    a0 = func_021590D4(v0, a1);
loc_0215AA42:
a0 = 0;
*(int *)&((struct Obj00005 *)t4)->f1C = a0;
    return a0;}
