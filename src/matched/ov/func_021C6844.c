/*
 * function: FIELD_G3DOBJ_GetObjectRedrawFlag
 * address:  0x021C6844
 * packet:   pkt_021C6844
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
#include "../include/Obj18312.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FIELD_G3DOBJ_GetObjectRedrawFlag(int a, int b)
{
return ((*(u32 *)((u8 *)(((struct Obj18312 *)((u8 *)(a)))->fC) + ((b * 104))) << 26) >> 31);
}

