/*
 * function: func_021892B4
 * address:  0x021892B4
 * packet:   pkt_021892B4
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
 *   func_0216D2AC  0x0216D2AC  thumb  ov010
 *   func_0216CD50  0x0216CD50  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09172.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0216CD50(int a0);
extern void func_0216D2AC(u32 x);

int func_021892B4(u8 *a)
{
func_0216D2AC(((struct Obj09172 *)((u8 *)(a)))->f38);
func_0216CD50(((struct Obj09172 *)((u8 *)(a)))->f38);
((struct Obj09172 *)((u8 *)(a)))->f38 = 0;
return 0;
}

