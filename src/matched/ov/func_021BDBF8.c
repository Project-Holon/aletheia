/*
 * function: func_021BDBF8
 * address:  0x021BDBF8
 * packet:   pkt_021BDBF8
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
 *   func_02012A30  0x02012A30  thumb
 *   func_02029D7C  0x02029D7C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02661.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct BigObj;
extern u32 func_02012A30(const struct BigObj *p);
extern u32 func_02029D7C(u32, u32);

int func_021BDBF8(u32 a)
{
return func_02029D7C(func_02012A30((const struct BigObj *)*(u32 *)((u8 *)(*(u32 *)&((struct Obj02661 *)((u8 *)(a)))->f0) + 8)), *(u32 *)((u8 *)(*(u32 *)&((struct Obj02661 *)((u8 *)(a)))->f0) + 8));
}

