/*
 * function: func_021C2430
 * address:  0x021C2430
 * packet:   pkt_ov208_021C2430
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D63C  0x0207D63C  arm
 */
#include "../include/Obj14657.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void func_0207D63C(u32 r, int a, int b, int c, int d);
typedef enum { ONE = 1 } One;

void func_021C2430(u8 *p)
{
    One one = ONE;
    ((struct Obj14657 *)p)->f1D8 = one;
    ((struct Obj14657 *)p)->f1DC = one << 15;
    func_0207D63C(0x04000050, 0, 0x3f, one, 16 - one);
}
