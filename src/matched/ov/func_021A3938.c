/*
 * function: func_021A3938
 * address:  0x021A3938
 * packet:   pkt_021A3938
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
 *   func_021A3AD8  0x021A3AD8  thumb  ov021
 *   func_02012B30  0x02012B30  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18034.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02012B30(u32, u32);
extern void func_021A3AD8(u8 *p, int a);

int func_021A3938(u32 a, u32 b)
{
func_021A3AD8((u8 *)a, b);
return func_02012B30(((struct Obj18034 *)((u8 *)(a)))->fC, b);
}

