/*
 * function: func_021A05D8
 * address:  0x021A05D8
 * packet:   pkt_ov021_021A05D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A07B0  0x021A07B0  thumb  ov021
 *   func_021A0734  0x021A0734  thumb  ov021
 *   func_021A07B4  0x021A07B4  thumb  ov021
 *   func_021A0974  0x021A0974  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09537.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void func_021A07B0(void);
extern void func_021A0734(u8 *a, u32 b);
extern u32 func_021A07B4(u8 *p, int t);
extern void func_021A0974(u32 a1, u32 a2, u32 a3);

void func_021A05D8(u8 *a)
{
    u32 r;

    func_021A07B0();
    func_021A0734(a, ((struct Obj09537 *)a)->f354);
    r = func_021A07B4(a, ((struct Obj09537 *)a)->f48C);
    ((struct Obj09537 *)a)->f350 = r;
    func_021A0974((u32)(a + 0x390), (u32)(a + 0x356), (u32)(a + 0x10 + r * 0x34));
}
