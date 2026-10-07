/*
 * function: func_02197E10
 * address:  0x02197E10
 * packet:   pkt_02197E10
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
 *   func_0216D410  0x0216D410  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../../../matched/include/Obj09177.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_0216D410(void *a0, u16 a1);

int func_02197E10(u32 a, u32 b, u32 c, u32 d)
{
func_0216D410((void *)(((struct Obj09177 *)((u8 *)(a)))->fC), *(u16 *)((u8 *)(((struct Obj09177 *)((u8 *)(a)))->f10)));
((struct Obj09177 *)((u8 *)(a)))->f0 = 3;
return 0;
}

