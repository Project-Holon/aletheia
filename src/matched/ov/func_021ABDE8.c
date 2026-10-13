/*
 * function: FIELD_EFFECT_Delete
 * address:  0x021ABDE8
 * packet:   pkt_021ABDE8
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
 *   FIELD_EFFECT_ExitObjectSystem  0x021ABFC0  thumb  ov021
 *   FIELD_EFFECT_FreeResourceTable  0x021ABEE8  thumb  ov021
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02708.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(u32 arc);
extern u32 FIELD_EFFECT_FreeResourceTable(u32);
extern u32 FIELD_EFFECT_ExitObjectSystem(u32, u32, u32, u32);

int FIELD_EFFECT_Delete(void *a, u32 b, u32 c, u32 d)
{
FIELD_EFFECT_ExitObjectSystem((u32)a, b, c, d);
FIELD_EFFECT_FreeResourceTable((u32)a);
ARC_TOOL_DeleteHandle(((struct Obj02708 *)((u8 *)(a)))->fC);
return func_020307B0(a);
}

