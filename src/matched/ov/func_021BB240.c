/*
 * function: FIELD_NOGRID_MAPPER_Delete
 * address:  0x021BB240
 * packet:   pkt_021BB240
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
 *   RAIL_ATTR_Delete  0x021BB0A4  thumb  ov021
 *   FIELD_RAIL_Delete  0x021B791C  thumb  ov021
 *   FIELD_RAIL_LOADER_Delete  0x0219EF6C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09191.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
extern void FIELD_RAIL_LOADER_Delete(u8 *p);
extern void FIELD_RAIL_Delete(void **o);
extern void RAIL_ATTR_Delete(u8 *p, u32 a1, u32 a2, u32 a3);

int FIELD_NOGRID_MAPPER_Delete(void *a, u32 b, u32 c, u32 d)
{
RAIL_ATTR_Delete((u8 *)(((struct Obj09191 *)((u8 *)(a)))->f8), b, c, d);
FIELD_RAIL_Delete((void **)(((struct Obj09191 *)((u8 *)(a)))->f0));
FIELD_RAIL_LOADER_Delete((u8 *)(((struct Obj09191 *)((u8 *)(a)))->f4));
return func_020307B0(a);
}

