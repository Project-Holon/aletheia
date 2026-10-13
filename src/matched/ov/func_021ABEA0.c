/*
 * function: FIELD_EFFECT_GetResource
 * address:  0x021ABEA0
 * packet:   pkt_021ABEA0
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
 *   FIELD_EFFECT_FindResourceSlot  0x021ABF2C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18084.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_EFFECT_FindResourceSlot(u32, u32);

int FIELD_EFFECT_GetResource(u32 a, u32 b)
{
return ((struct Obj18084 *)((u8 *)(FIELD_EFFECT_FindResourceSlot(a, b))))->f4;
}

