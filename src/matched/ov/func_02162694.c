/*
 * function: func_02162694
 * address:  0x02162694
 * packet:   pkt_02162694
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201416C  0x0201416C  thumb
 */
#include "../include/Obj00193.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0201416C(int a0, int a1, int a2, int a3);

int func_02162694(int a0, int a1, int a2)
{
    int a3;
    int t4;

t4 = a0 + 0;
a3 = a2 + 0;
a0 = a1 + 0;
a1 = *(u16 *)&((struct Obj00193 *)((char *)t4))->f0;
a2 = *(u16 *)((char *)t4 + 2);
    a0 = func_0201416C(a0, a1, a2, a3);
loc_021626A4:
    return a0;}
