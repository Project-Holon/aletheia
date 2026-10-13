/*
 * function: func_021C674C
 * address:  0x021C674C
 * packet:   pkt_021C674C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23596.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void ARC_TOOL_DeleteHandle(void *);

void func_021C674C(u8 *p)
{
    ARC_TOOL_DeleteHandle(((struct Obj23596 *)p)->f290);
}
