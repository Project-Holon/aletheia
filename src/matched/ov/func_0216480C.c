/*
 * function: func_0216480C
 * address:  0x0216480C
 * packet:   pkt_0216480C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049238  0x02049238  arm
 */
#include "../include/Obj12049.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02049238(void *arc);

int func_0216480C(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj12049 *)t4)->f8;
    func_02049238((void *)a0);
loc_02164816:
a0 = 0;
((struct Obj12049 *)t4)->f8 = a0;
    return a0;}
