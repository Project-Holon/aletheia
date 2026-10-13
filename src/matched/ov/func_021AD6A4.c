/*
 * function: FLDEFF_NAMIPOKE_SPLASH_Exit
 * address:  0x021AD6A4
 * packet:   pkt_021AD6A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_G3DOBJ_DeleteObject  0x021C6628  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12097.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_EFFECT_GetFieldMapData(u8 *p);
extern u32 FIELD_G3DOBJ_DeleteObject(u32, u32);

int FLDEFF_NAMIPOKE_SPLASH_Exit(u32 a, u32 b, u32 c, u32 d)
{
return FIELD_G3DOBJ_DeleteObject(FIELD_EFFECT_GetFieldMapData((u8 *)(*(u32 *)((u8 *)(((struct Obj12097 *)((u8 *)(b)))->f18)))), ((struct Obj12097 *)((u8 *)(b)))->f10);
}

