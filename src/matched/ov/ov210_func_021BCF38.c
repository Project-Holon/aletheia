/*
 * function: func_021BCF38
 * address:  0x021BCF38
 * packet:   pkt_021BCF38
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021C0720  0x021C0720  data  ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25593.h"
#include "../include/Obj25594.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u8 d_021C0720[];

void func_021BCF38(u8 *p)
{
    u8 *r0 = *(u8 * *)&((struct Obj25593 *)p)->f0;
    u8 *r2 = *(u8 * *)&((struct Obj25594 *)r0)->f8;
    u8 r1 = r2[6];

    if (r1 != 0xff) {
        r2[6] = d_021C0720[r1];
    }
}
