/*
 * function: func_0218E160
 * address:  0x0218E160
 * packet:   pkt_0218E160
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
 *   func_0218E124  0x0218E124  thumb  ov021
 *   func_0218E18C  0x0218E18C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01653.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0218E124(u8 *a, u32 s);
extern u32 func_0218E18C(u32, u32);

int func_0218E160(u32 a)
{
func_0218E124((u8 *)a, 0);
func_0218E18C(a, ((struct Obj01653 *)((u8 *)(a)))->f18);
*(u8 *)((u8 *)((a + 233))) = 1;
return 1;
}

