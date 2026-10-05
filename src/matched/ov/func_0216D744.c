/*
 * function: func_0216D744
 * address:  0x0216D744
 * packet:   pkt_0216D744
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
#include "../include/Obj00113.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int func_0216D744(int a0, int a1)
{

a1 = a0 + 0;
a1 = a1 + 0x90;
a1 = *(int *)&((struct Obj00113 *)((char *)a1))->f0;
a1 = *(int *)&((struct Obj00113 *)((char *)a1))->f0;
    if (a1 == 0) goto loc_0216D754;
loc_0216D752:
    a0 = ((int (*)())a1)();
loc_0216D754:
    return a0;}
