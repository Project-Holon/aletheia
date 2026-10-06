/*
 * function: func_021A0590
 * address:  0x021A0590
 * packet:   pkt_ov021_021A0590
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A07B0  0x021A07B0  thumb  ov021
 *   func_021A0748  0x021A0748  thumb  ov021
 *   func_021A07B4  0x021A07B4  thumb  ov021
 *   func_021A0980  0x021A0980  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12698.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void func_021A07B0(void);
extern void func_021A0748(u8 *a, u32 b, u32 c);
extern u32 func_021A07B4(u8 *p, int t);
extern void func_021A0980(u8 *a, u8 *b, u8 *c, u32 d);

void func_021A0590(u8 *a, u32 b, u32 c, u32 d)
{
    u32 r;

    func_021A07B0();
    func_021A0748(a, b, c);
    r = func_021A07B4(a, ((struct Obj12698 *)a)->f48C);
    ((struct Obj12698 *)a)->f350 = r;
    func_021A0980(a + 0x390, a + 0x356, a + 0x10 + r * 0x34, d);
}
