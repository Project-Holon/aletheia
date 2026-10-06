/*
 * function: func_021ADF68
 * address:  0x021ADF68
 * packet:   pkt_021ADF68
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
 *   func_02047738  0x02047738  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047504  0x02047504  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_020470D0  0x020470D0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04889.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02046EFC(u32);
struct Rec;
extern int func_020470D0(u32 *p);
extern void func_02047504(struct Rec *p);
extern void func_0204762C(struct Rec *p);
extern void func_02047738(struct Rec *p);

int func_021ADF68(u32 a, u32 b, u32 c, u32 d)
{
func_02047738((struct Rec *)(((struct Obj04889 *)((u8 *)(a)))->fC));
func_0204762C((struct Rec *)(((struct Obj04889 *)((u8 *)(a)))->f10));
func_02047504((struct Rec *)(((struct Obj04889 *)((u8 *)(a)))->f14));
func_02046EFC(((struct Obj04889 *)((u8 *)(a)))->f8);
func_020470D0((u32 *)(((struct Obj04889 *)((u8 *)(a)))->f4));
return func_02046EFC(((struct Obj04889 *)((u8 *)(a)))->f4);
}

