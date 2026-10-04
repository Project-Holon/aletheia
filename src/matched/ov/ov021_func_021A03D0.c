/*
 * function: func_021A03D0
 * address:  0x021A03D0
 * packet:   pkt_ov021_021A03D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_021A0734  0x021A0734  thumb  ov021
 *   func_021A07B4  0x021A07B4  thumb  ov021
 *   func_02082D44  0x02082D44  arm
 *   d_021DDE38  0x021DDE38  data  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04229.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_02030734(u32 a, u32 b, int c, const char *d, u16 e);
extern void func_021A0734(u8 *a, u32 b);
extern u32 func_021A07B4(u8 *p, int t);
extern void func_02082D44(void *src, void *dst, u32 n);
extern u8 d_021DDE38[];

u8 *func_021A03D0(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f)
{
    u8 *p;

    p = func_02030734(f, 0x490, 1, (const char *)d_021DDE38, 0x167);
    ((struct Obj04229 *)p)->f2 = c;
    func_021A0734(p, a);
    ((struct Obj04229 *)p)->f38A = 1;
    ((struct Obj04229 *)p)->f350 = func_021A07B4(p, b);
    func_02082D44(p + 0x10 + ((struct Obj04229 *)p)->f350 * 0x34, p + 0x356, 0x34);
    ((struct Obj04229 *)p)->f38C = 1;
    ((struct Obj04229 *)p)->f8 = d;
    ((struct Obj04229 *)p)->f4 = e;
    return p;
}
