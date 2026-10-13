/*
 * function: FIELD_BUILDMODEL_GetPlacementByTableId
 * address:  0x0218B910
 * packet:   pkt_0218B910
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_BUILDMODEL_GetModelIndex  0x0218BBD0  thumb  ov021
 *   FIELD_BUILDMODEL_GetOffsetTarget  0x0218BBF4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09453.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_BUILDMODEL_GetModelIndex(u32, u32);
extern int FIELD_BUILDMODEL_GetOffsetTarget(u32 a, u32 b);

int FIELD_BUILDMODEL_GetPlacementByTableId(u32 a, u32 b)
{
return FIELD_BUILDMODEL_GetOffsetTarget(((struct Obj09453 *)((u8 *)(a)))->f18, FIELD_BUILDMODEL_GetModelIndex(a, b));
}

