/*
 * function: func_021B9D04
 * address:  0x021B9D04
 * packet:   pkt_ov181_021B9D04
 * region:   ov181
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   func_021B9B98  0x021B9B98  thumb  ov181
 */
#include "../include/Obj24503.h"

typedef unsigned int   u32;
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern void func_021B9B98(char *);

void func_021B9D04(char *p)
{
    ((struct Obj24503 *)p)->f2D4 = (int)ARC_TOOL_LoadMember(0xdc, 1, 0x8e);
    func_021B9B98(p);
}
