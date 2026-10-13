/*
 * function: FIELD_BUILDMODEL_FreeEntry
 * address:  0x0218C518
 * packet:   pkt_0218C518
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * FIELD_G3D_MAP_ClearPlacement (0x0216940C) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_G3D_MAP_ClearPlacement  0x0216940C  thumb
 *   FIELD_BUILDMODEL_ClearEntry  0x0218C490  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03573.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_G3D_MAP_ClearPlacement(u32, u32, u32, u32);
extern u32 FIELD_BUILDMODEL_ClearEntry(u32, u32);

int FIELD_BUILDMODEL_FreeEntry(u32 a, u32 b, u32 c, u32 d)
{
FIELD_G3D_MAP_ClearPlacement(*(u32 *)&((struct Obj03573 *)((u8 *)(b)))->f0, ((struct Obj03573 *)((u8 *)(b)))->f8, c, d);
return FIELD_BUILDMODEL_ClearEntry(a, b);
}

