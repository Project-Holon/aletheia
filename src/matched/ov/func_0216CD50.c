/*
 * function: func_0216CD50
 * address:  0x0216CD50
 * packet:   pkt_0216CD50
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02197C4C  0x02197C4C  thumb
 *   func_0216CD30  0x0216CD30  thumb  ov010
 */
#include "../include/Obj17770.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02197C4C();
extern int func_0216CD30();

int func_0216CD50(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02197C4C(a0);
loc_0216CD58:
a0 = 0;
((struct Obj17770 *)t4)->f40 = a0;
a0 = t4 + 0;
    a0 = func_0216CD30(a0);
loc_0216CD62:
    return a0;}
