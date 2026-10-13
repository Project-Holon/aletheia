/*
 * function: FIELD_BBD_COLOR_Delete
 * address:  0x021CD1F0
 * packet:   pkt_021CD1F0
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
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18362.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(u32 arc);

int FIELD_BBD_COLOR_Delete(void *a)
{
ARC_TOOL_DeleteHandle(((struct Obj18362 *)((u8 *)(a)))->f0);
return func_020307B0(a);
}

