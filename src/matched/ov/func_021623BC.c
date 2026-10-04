/*
 * function: func_021623BC
 * address:  0x021623BC
 * packet:   pkt_021623BC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj09161.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02049238(void *arc);
extern int func_020307B0();

int func_021623BC(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj09161 *)t4)->f4;
    func_02049238((void *)a0);
loc_021623C6:
a0 = ((struct Obj09161 *)t4)->f8;
    func_02049238((void *)a0);
loc_021623CC:
a0 = ((struct Obj09161 *)t4)->fC;
    func_02049238((void *)a0);
loc_021623D2:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_021623D8:
    return a0;}
