/*
 * function: func_021A5A68
 * address:  0x021A5A68
 * packet:   pkt_ov021_021A5A68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A5C3C  0x021A5C3C  thumb  ov021
 *   func_021A6014  0x021A6014  thumb  ov021
 *   func_021A64B4  0x021A64B4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04234.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021A3974(u32 a);
extern int func_021A5C3C(u8 *p, u32 a, u32 b, u32 c, u32 d);
extern int func_021A6014(int *a, int b, int c, int d, int e);
extern int func_021A64B4(int *a, int b, int c, int d, int e);

int func_021A5A68(u8 *p, u32 a, u32 b, u32 c, u32 d)
{
    int r;

    switch (func_021A3974(*(u32 *)&((struct Obj04234 *)p)->f14)) {
    case 0:
        r = func_021A5C3C(p, b, c, (u16)a, d);
        break;
    case 1:
        r = func_021A6014((int *)p, b, c, (u16)a, d);
        break;
    case 2:
    case 3:
        r = func_021A64B4((int *)p, b, c, (u16)a, d);
        break;
    }
    return r;
}
