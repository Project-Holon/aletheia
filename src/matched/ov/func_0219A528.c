/*
 * function: func_0219A528
 * address:  0x0219A528
 * packet:   pkt_0219A528
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216DA50 (0x0216DA50) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216DA50  0x0216DA50  thumb
 *   func_02163F10  0x02163F10  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17954.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02163F10(u32);
extern void func_0216D674(void *p, u16 v);
extern u32 func_0216D684(u32, u32, u32, u32);
extern u32 func_0216DA50(u32);

int func_0219A528(u32 a, u32 b, u32 c, u32 d)
{
((struct Obj17954 *)((u8 *)(func_0216D684(a, 8, c, d))))->f0 = b;
func_0216D674((void *)a, 0);
func_0216DA50(a);
return func_02163F10(a);
}

