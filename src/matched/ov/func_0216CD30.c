/*
 * function: FLDMMDL_ReleaseSysProc
 * address:  0x0216CD30
 * packet:   pkt_0216CD30
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030DA4  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   FLDMMDL_SysClearStatusBit  0x0216D4E4  thumb  ov010
 */
#include "../include/Obj09166.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02030DA4();
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *arc);
extern u32 *FLDMMDL_SysClearStatusBit(u32 *p, u32 v);

void FLDMMDL_ReleaseSysProc(u32 *a0, int a1)
{
    int t4;

t4 = (int)(a0 + 0);
a0 = (u32 *)(((struct Obj09166 *)t4)->f20);
    a0 = (u32 *)func_02030DA4(a0);
loc_0216CD3A:
a0 = (u32 *)(((struct Obj09166 *)t4)->f1C);
    a0 = (u32 *)func_020307B0(a0);
loc_0216CD40:
a0 = (u32 *)(((struct Obj09166 *)t4)->f10);
    ARC_TOOL_DeleteHandle((void *)a0);
loc_0216CD46:
a0 = (u32 *)(t4 + 0);
a1 = 0x10;
    a0 = (u32 *)FLDMMDL_SysClearStatusBit(a0, a1);
loc_0216CD4E:
    return;}
