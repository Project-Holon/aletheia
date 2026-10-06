/*
 * function: func_021BD19C
 * address:  0x021BD19C
 * packet:   pkt_021BD19C
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
 *   func_021BD2C4  0x021BD2C4  thumb  ov021
 *   func_021BD2D0  0x021BD2D0  thumb  ov021
 *   func_021BD30C  0x021BD30C  thumb  ov021
 *   func_021BD57C  0x021BD57C  thumb  ov021
 *   func_021BD588  0x021BD588  thumb  ov021
 *   func_021BD554  0x021BD554  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12115.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021BD2C4(u8 *p, u32 v);
extern void func_021BD2D0(u8 *p, u16 v);
extern void func_021BD30C(char *p);
extern u32 func_021BD554(u32, u32);
extern void func_021BD57C(u8 *p);
extern void func_021BD588(u32 *p);

int func_021BD19C(u32 a, u32 b)
{
func_021BD2C4((u8 *)a, ((struct Obj12115 *)((u8 *)(b)))->f20);
func_021BD2D0((u8 *)a, ((struct Obj12115 *)((u8 *)(b)))->f24);
func_021BD30C((char *)a);
func_021BD57C((u8 *)a);
func_021BD588((u32 *)a);
return func_021BD554(a, b);
}

