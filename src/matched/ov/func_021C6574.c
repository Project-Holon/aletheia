/*
 * function: FIELD_G3DOBJ_AddResourceDefaultPal
 * address:  0x021C6574
 * packet:   pkt_021C6574
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
 *   FIELD_G3DOBJ_AddResource  0x021C6538  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18309.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_G3DOBJ_AddResource(u32, u32, u32, u32);

int FIELD_G3DOBJ_AddResourceDefaultPal(u32 a, u32 b, u32 c)
{
    return FIELD_G3DOBJ_AddResource(a, b, c, ((struct Obj18309 *)((u8 *)(a)))->f10);
}

