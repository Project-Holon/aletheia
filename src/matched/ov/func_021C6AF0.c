/*
 * function: FIELD_G3DOBJ_SetResDescModel
 * address:  0x021C6AF0
 * packet:   pkt_021C6AF0
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
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06084.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FIELD_G3DOBJ_SetResDescModel(u32 a, u32 b, u32 c)
{
((struct Obj06084 *)((u8 *)(a)))->f0 = b;
((struct Obj06084 *)((u8 *)(a)))->fC = c;
return a;
}

