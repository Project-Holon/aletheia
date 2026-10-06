/*
 * function: func_0216D600
 * address:  0x0216D600
 * packet:   pkt_0216D600
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none: no relocation site)
 */
#include "../include/Obj00113.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int func_0216D600(int a0, u16 a1)
{
    int a2;

a2 = ((struct Obj00113 *)a0)->f1A;
((struct Obj00113 *)a0)->f1E = a2;
((struct Obj00113 *)a0)->f1A = a1;
    return a0;}
