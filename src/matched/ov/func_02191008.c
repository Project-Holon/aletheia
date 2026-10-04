/*
 * function: func_02191008
 * address:  0x02191008
 * packet:   pkt_02191008
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
 *   func_02192BC0  0x02192BC0  thumb  ov021
 *   func_02190D48  0x02190D48  thumb  ov021
 *   func_02190538  0x02190538  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_021927E8  0x021927E8  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00005.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
struct Slot;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_02190538(struct Slot *s);
extern int func_02190D48(u32 a);
extern void func_021927E8(u32 *p);
extern void func_02192BC0(u8 *p);

int func_02191008(u32 a)
{
func_02192BC0((u8 *)(((struct Obj00005 *)((u8 *)(a)))->f0));
if (((struct Obj00005 *)((u8 *)(a)))->f4 != 0) {
    func_02190D48(((struct Obj00005 *)((u8 *)(a)))->f4);
}
if (*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8 != 0) {
    func_02190538((struct Slot *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8));
}
func_02045808((struct U16Vec *)(((struct Obj00005 *)((u8 *)(a)))->f10));
func_021927E8((u32 *)(a + 24));
return func_020307B0(a);
}

