/*
 * function: func_021F45EC
 * address:  0x021F45EC
 * packet:   pkt_021F45EC
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F462C  0x021F462C  thumb  ov194
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24920.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_02082BCC(u8 *, u32, u32);
extern void func_021F462C(u8 *, u32);

void func_021F45EC(u8 *a, u32 b, u32 c)
{
    func_02082BCC(a, 0, 0x10);
    ((struct Obj24920 *)a)->fC = b;
    func_021F462C(a, c);
}

