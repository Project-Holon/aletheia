/*
 * function: SCRIPT_WORK_CmdJump
 * address:  0x02159658
 * packet:   pkt_02159658
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   VM_Jump  0x020113B0  thumb
 */
#include "../include/Obj00005.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int VM_GetU32();
extern int VM_Jump();

int SCRIPT_WORK_CmdJump(int a0, int a1, int a2)
{
    int t4;

t4 = a0 + 0;
    a0 = VM_GetU32(a0);
loc_02159660:
a2 = a0 + 0;
a1 = *(int *)&((struct Obj00005 *)t4)->f14;
a0 = t4 + 0;
a1 = a1 + a2;
    a0 = VM_Jump(a0, a1, a2);
loc_0215966C:
a0 = 0;
    return a0;}
