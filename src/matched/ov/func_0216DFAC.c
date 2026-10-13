/*
 * function: FLDMMDL_DeleteMoveTcb
 * address:  0x0216DFAC
 * packet:   pkt_0216DFAC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 */
#include "../include/Obj00113.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02030EAC();

int FLDMMDL_DeleteMoveTcb(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = a0 + 0x84;
a0 = *(int *)&((struct Obj00113 *)((char *)a0))->f0;
    if (a0 == 0) goto loc_0216DFC2;
loc_0216DFB8:
    a0 = func_02030EAC(a0);
loc_0216DFBC:
a0 = 0;
t4 = t4 + 0x84;
*(int *)&((struct Obj00113 *)((char *)t4))->f0 = a0;
loc_0216DFC2:
    return a0;}
