/*
 * function: func_021A752C
 * address:  0x021A752C
 * packet:   pkt_021A752C
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
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12091.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_020307B0(void *p);

int func_021A752C(u32 a)
{
func_020307B0((void *)(((struct Obj12091 *)((u8 *)(a)))->f4));
((struct Obj12091 *)((u8 *)(a)))->f4 = 0;
return 0;
}

