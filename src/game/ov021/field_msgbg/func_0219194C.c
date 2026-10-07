/*
 * function: func_0219194C
 * address:  0x0219194C
 * packet:   pkt_0219194C
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
 *   func_02045808  0x02045808  arm
 *   func_0219492C  0x0219492C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../../../matched/include/Obj07210.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_0219492C(u8 *p, int i);

int func_0219194C(void *a)
{
if (((struct Obj07210 *)((u8 *)(a)))->f0 != 0) {
    func_02045808((struct U16Vec *)(((struct Obj07210 *)((u8 *)(a)))->f0));
}
func_0219492C((u8 *)(((struct Obj07210 *)((u8 *)(a)))->fC), ((struct Obj07210 *)((u8 *)(a)))->f8);
return func_020307B0(a);
}

