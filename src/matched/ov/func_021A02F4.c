/*
 * function: FIELD_ZONEFOG_Delete
 * address:  0x021A02F4
 * packet:   pkt_021A02F4
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
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   FIELD_ZONEFOG_Clear  0x021A0358  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17987.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(u32 arc);
extern u32 FIELD_ZONEFOG_Clear(u32);

int FIELD_ZONEFOG_Delete(void *a)
{
ARC_TOOL_DeleteHandle(((struct Obj17987 *)((u8 *)(a)))->fC);
FIELD_ZONEFOG_Clear((u32)a);
return func_020307B0(a);
}

