/*
 * function: SCRIPT_WORK_FreeUserWork
 * address:  0x02158FBC
 * packet:   pkt_02158FBC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_020307B0();

void SCRIPT_WORK_FreeUserWork(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj00005 *)t4)->f3C;
    if (a0 == 0) goto loc_02158FCE;
loc_02158FC6:
    a0 = func_020307B0(a0);
loc_02158FCA:
a0 = 0;
((struct Obj00005 *)t4)->f3C = a0;
loc_02158FCE:
    return;}
