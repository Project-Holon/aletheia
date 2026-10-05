/*
 * function: func_0216544C
 * address:  0x0216544C
 * packet:   pkt_0216544C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020270AC  0x020270AC  thumb
 *   func_0202744C  0x0202744C  thumb
 */
#include "../include/Obj00121.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020270AC();
extern int func_0202744C();

int func_0216544C(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = 0x1f;
((struct Obj00121 *)t4)->f30 = a0;
a0 = a1 + 0;
a1 = t4 + 0;
a1 = a1 + 0x34;
    a0 = func_020270AC(a0, a1);
loc_0216545E:
a0 = t4 + 0;
    a0 = func_0202744C(a0);
loc_02165464:
    return a0;}
