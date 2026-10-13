/*
 * function: func_021E10DC
 * address:  0x021E10DC
 * packet:   pkt_021E10DC
 * region:   ov183
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 */
#include "../include/Obj24626.h"

typedef unsigned short u16;

typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_TOOL_DeleteHandle(void *arc);

void func_021E10DC(char *p)
{
    ARC_TOOL_DeleteHandle(func_020490F4(0x17, ((struct Obj24626 *)p)->f34C));
}
