/*
 * function: func_0218C518
 * address:  0x0218C518
 * packet:   pkt_0218C518
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216940C (0x0216940C) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0216940C  0x0216940C  thumb
 *   func_0218C490  0x0218C490  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../../../matched/include/Obj03573.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216940C(u32, u32, u32, u32);
extern u32 func_0218C490(u32, u32);

int func_0218C518(u32 a, u32 b, u32 c, u32 d)
{
func_0216940C(*(u32 *)&((struct Obj03573 *)((u8 *)(b)))->f0, ((struct Obj03573 *)((u8 *)(b)))->f8, c, d);
return func_0218C490(a, b);
}

