/*
 * function: FIELD_G3D_MAPPER_SetupWfbc
 * address:  0x0218DC74
 * packet:   pkt_0218DC74
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
 *   FIELD_WFBC_SetUp  0x02193B04  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12063.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FIELD_WFBC_SetUp(u32 a, u32 b, u32 c, u32 d);

int FIELD_G3D_MAPPER_SetupWfbc(u32 a, u32 b, u32 c)
{
return FIELD_WFBC_SetUp(((struct Obj12063 *)((u8 *)(a)))->f6C, b, c, ((struct Obj12063 *)((u8 *)(a)))->f0);
}

