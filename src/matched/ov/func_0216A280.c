/*
 * function: func_0216A280
 * address:  0x0216A280
 * packet:   pkt_0216A280
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D11D8  0x021D11D8  thumb
 *   func_021D1194  0x021D1194  thumb
 */
#include "../include/Obj00029.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D11D8();
extern int func_021D1194();

int func_0216A280(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = *(int *)&((struct Obj00029 *)a0)->f48;
    a0 = func_021D11D8(a0);
loc_0216A28C:
a0 = *(int *)&((struct Obj00029 *)t4)->f18;
a0 = *(int *)&((struct Obj00029 *)a0)->f48;
    a0 = func_021D1194(a0);
loc_0216A294:
    return a0;}
