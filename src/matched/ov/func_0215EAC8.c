/*
 * function: func_0215EAC8
 * address:  0x0215EAC8
 * packet:   pkt_0215EAC8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215F104  0x0215F104  thumb  ov010
 */
#include "../include/Obj17698.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215F104();

int func_0215EAC8(int a0, int a1)
{
    int t4;

a1 = ((struct Obj17698 *)a0)->f4;
    if (a1 != 2) goto loc_0215EAD4;
loc_0215EAD0:
a0 = 4;
    return a0;
loc_0215EAD4:
    if (a1 != 3) goto loc_0215EADC;
loc_0215EAD8:
a0 = 1;
    return a0;
loc_0215EADC:
a1 = 1;
t4 = 1;
    a0 = func_0215F104(a0, a1);
loc_0215EAE4:
    if (a0 == 0) goto loc_0215EAEA;
loc_0215EAE8:
t4 = 0;
loc_0215EAEA:
a0 = t4 + 0;
    return a0;}
