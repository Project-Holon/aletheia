/*
 * function: func_02168AC8
 * address:  0x02168AC8
 * packet:   pkt_02168AC8
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
#include "../include/Obj12052.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;



int func_02168AC8(int a0, int a1, int a2, int a3)
{

a3 = 0;
loc_02168ACA:
a1 = a3 << 1;
a2 = a0 + a1;
a1 = ((struct Obj12052 *)a2)->f20;
    if (a1 == 0) goto loc_02168AD8;
loc_02168AD4:
a0 = 1;
    return a0;
loc_02168AD8:
a1 = ((struct Obj12052 *)a2)->f28;
    if (a1 == 0) goto loc_02168AE2;
loc_02168ADE:
a0 = 1;
    return a0;
loc_02168AE2:
a3 = a3 + 1;
    if (a3 < 4) goto loc_02168ACA;
loc_02168AE8:
a0 = 0;
    return a0;}
