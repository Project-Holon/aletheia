/*
 * function: func_021636C8
 * address:  0x021636C8
 * packet:   pkt_021636C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AB3D4  0x021AB3D4  thumb
 */
#include "../include/Obj07203.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021AB3D4();

int func_021636C8(int a0, int a1, int a2)
{

a2 = ((struct Obj07203 *)a0)->fE;
a1 = 0x80;
    if ((a1 & a2) != 0) goto loc_021636D6;
loc_021636D2:
a0 = 0;
    return a0;
loc_021636D6:
a1 = ((struct Obj07203 *)a0)->f18;
    if (a1 != 3) goto loc_021636EA;
loc_021636DC:
a0 = ((struct Obj07203 *)a0)->fA;
    a0 = func_021AB3D4(a0);
loc_021636E2:
    if (a0 == 0) goto loc_021636EA;
loc_021636E6:
a0 = 0;
    return a0;
loc_021636EA:
a0 = 1;
    return a0;}
