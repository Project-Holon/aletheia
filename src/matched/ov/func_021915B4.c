/*
 * function: func_021915B4
 * address:  0x021915B4
 * packet:   pkt_021915B4
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
 *   func_02190D48  0x02190D48  thumb  ov021
 *   func_02190538  0x02190538  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_02194A48  0x02194A48  thumb  ov021
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
extern u32 func_020307B0(void *p);
struct Slot;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_02190538(struct Slot *s);
extern int func_02190D48(void *a);
extern void func_021927E8(u32 *p);
extern u32 func_02194A48(u32, u32);

int func_021915B4(void *a)
{
if (*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f1C != 0) {
    func_02190D48((void *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f1C));
}
if (*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f20 != 0) {
    func_02190538((struct Slot *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f20));
}
if (*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8 != 0) {
    func_02045808((struct U16Vec *)(*(u32 *)&((struct Obj00005 *)((u8 *)(a)))->f8));
}
func_02194A48(((struct Obj00005 *)((u8 *)(a)))->f10, ((struct Obj00005 *)((u8 *)(a)))->f18);
func_021927E8((u32 *)a);
return func_020307B0(a);
}

