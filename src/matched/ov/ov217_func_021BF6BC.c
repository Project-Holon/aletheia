/*
 * function: func_021BF6BC
 * address:  0x021BF6BC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021BF6BC  0x021BF6BC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25930.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_02021D50();
extern u32 func_020419E4();
extern void func_0204A648(void);
u32 func_021BF6BC(u32 a0, u32 a1)
{
    func_020419E4();
    func_0204A648();
    return func_02021D50(((struct Obj25930 *)(((u8*)a1)))->f3B8);
}

