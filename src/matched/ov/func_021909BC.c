/*
 * function: func_021909BC
 * address:  0x021909BC
 * packet:   pkt_021909BC
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
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *   func_02193130  0x02193130  thumb  ov021
 *   func_02190538  0x02190538  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07209.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Obj;
struct Slot;
extern void func_0201F868(void *p);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32 func_020307B0(u32);
extern void func_02190538(struct Slot *s);
extern int func_02193130(u32 a);

int func_021909BC(u32 a)
{
func_0202020C((struct Obj *)(((struct Obj07209 *)((u8 *)(a)))->f10), 0, 0);
func_0201F868((void *)(((struct Obj07209 *)((u8 *)(a)))->fC));
func_02193130(((struct Obj07209 *)((u8 *)(a)))->f8);
func_02190538((struct Slot *)(((struct Obj07209 *)((u8 *)(a)))->f4));
return func_020307B0(a);
}

