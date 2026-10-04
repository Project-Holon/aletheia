/*
 * function: func_0215A5A4
 * address:  0x0215A5A4
 * packet:   pkt_0215A5A4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0215A738  0x0215A738  thumb  ov010
 */
#include "../include/Obj04882.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020307B0();
extern int func_02045C04();
extern int func_0215A738(int a0);

int func_0215A5A4(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj04882 *)t4)->f1C;
    if (a0 == 0) goto loc_0215A5B2;
loc_0215A5AE:
    a0 = func_020307B0(a0);
loc_0215A5B2:
a0 = ((struct Obj04882 *)t4)->f14;
    if (a0 == 0) goto loc_0215A5BC;
loc_0215A5B8:
    a0 = func_02045C04(a0);
loc_0215A5BC:
a0 = t4 + 0;
    a0 = func_0215A738(a0);
loc_0215A5C2:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0215A5C8:
    return a0;}
