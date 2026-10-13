/*
 * function: FIELD_PLACE_NAME_DeleteArcHandle
 * address:  0x021BC824
 * packet:   pkt_021BC824
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00575.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void ARC_TOOL_DeleteHandle(u32 v);

void FIELD_PLACE_NAME_DeleteArcHandle(u8 *p)
{
    u32 v = ((struct Obj00575 *)p)->f10;
    if (v != 0) {
        ARC_TOOL_DeleteHandle(v);
        ((struct Obj00575 *)p)->f10 = 0;
    }
}
