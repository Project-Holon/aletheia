/*
 * function: EVENTDATA_SYSTEM_Delete
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
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj09161.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void ARC_TOOL_DeleteHandle(void *arc);
extern int func_020307B0();

int EVENTDATA_SYSTEM_Delete(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj09161 *)t4)->f4;
    ARC_TOOL_DeleteHandle((void *)a0);
loc_021623C6:
a0 = ((struct Obj09161 *)t4)->f8;
    ARC_TOOL_DeleteHandle((void *)a0);
loc_021623CC:
a0 = ((struct Obj09161 *)t4)->fC;
    ARC_TOOL_DeleteHandle((void *)a0);
loc_021623D2:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_021623D8:
    return a0;}
