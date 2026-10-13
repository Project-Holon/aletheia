/*
 * function: FIELD_BUILDMODEL_GetModelDef
 * address:  0x0218B924
 * packet:   pkt_0218B924
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x18.
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetOffsetTarget  0x0218BBF4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17893.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_BUILDMODEL_GetOffsetTarget(u32 a, u32 b);

int FIELD_BUILDMODEL_GetModelDef(u8 *p, u32 a1)
{
    return FIELD_BUILDMODEL_GetOffsetTarget(((struct Obj17893 *)p)->f18, a1);
}
