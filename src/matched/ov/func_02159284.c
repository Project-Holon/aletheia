/*
 * function: SCRIPT_WORK_CmdCall
 * address:  0x02159284
 * packet:   pkt_02159284
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   VM_Call  0x020113B4  thumb
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int VM_GetU32();
extern int VM_Call();

int SCRIPT_WORK_CmdCall(int a0, int a1, int a2)
{
    int t4;

t4 = a0 + 0;
    a0 = VM_GetU32(a0);
loc_0215928C:
a2 = a0 + 0;
a1 = *(int *)&((struct Obj00005 *)t4)->f14;
a0 = t4 + 0;
a1 = a1 + a2;
    a0 = VM_Call(a0, a1, a2);
loc_02159298:
a0 = 0;
    return a0;}
