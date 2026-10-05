/*
 * function: func_02162298
 * address:  0x02162298
 * packet:   pkt_02162298
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   (none: no relocation site)
 */
#include "../include/Obj03062.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int func_02162298(int a0, int a1, int a2, int a3)
{

((struct Obj03062 *)a0)->f2E = a2;
a3 = ((struct Obj03062 *)a0)->f4;
((struct Obj03062 *)a0)->f2C = a1;
a2 = ((struct Obj03062 *)a0)->f2;
a1 = 0x10;
((struct Obj03062 *)a0)->f28 = a3;
a1 = a1 | a2;
((struct Obj03062 *)a0)->f2 = a1;
    return a0;}
