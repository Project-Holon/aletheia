/*
 * function: func_0218BB64
 * address:  0x0218BB64
 * packet:   pkt_0218BB64
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
#include "../include/Obj01114.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_020307B0(void *p);

int func_0218BB64(u32 a, u32 b, u32 c, u32 d)
{
func_020307B0((void *)(((struct Obj01114 *)((u8 *)(a)))->f18));
*(u16 *)((u8 *)(a) + ((107 << 2))) = 0;
return (107 << 2);
}

