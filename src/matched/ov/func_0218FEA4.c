/*
 * function: func_0218FEA4
 * address:  0x0218FEA4
 * packet:   pkt_0218FEA4
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
 *   func_0218FFE8  0x0218FFE8  thumb  ov021
 *   func_02190058  0x02190058  thumb  ov021
 *   func_021900A8  0x021900A8  thumb  ov021
 *   func_0218FF78  0x0218FF78  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02372.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0218FF78(u32);
extern u32 func_0218FFE8(u32, u32, u32, u32);
extern void func_02190058(u8 *o);
extern void func_021900A8(void *a);

int func_0218FEA4(u32 a, u32 b, u32 c, u32 d)
{
func_0218FFE8(a, b, c, d);
func_02190058((u8 *)(*(u32 *)&((struct Obj02372 *)((u8 *)(a)))->f4));
func_021900A8((void *)(*(u32 *)&((struct Obj02372 *)((u8 *)(a)))->f4));
return func_0218FF78(a);
}

