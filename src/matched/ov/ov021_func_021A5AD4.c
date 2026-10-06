/*
 * function: func_021A5AD4
 * address:  0x021A5AD4
 * packet:   pkt_ov021_021A5AD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A5BC0  0x021A5BC0  thumb  ov021
 *   func_021A5F98  0x021A5F98  thumb  ov021
 *   func_021A635C  0x021A635C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01119.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int  func_021A3974(u32 a);
extern void func_021A5BC0(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_021A5F98(int *a, u32 sel, u32 c, u32 d, u32 e, u32 f);
extern void func_021A635C(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);

void func_021A5AD4(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    switch (func_021A3974(*(u32 *)&((struct Obj01119 *)p)->f14)) {
    case 0:
        func_021A5BC0(p, a, c, d, (u16)b, e);
        break;
    case 1:
        func_021A5F98((int *)p, a, c, d, (u16)b, e);
        break;
    case 2:
    case 3:
        func_021A635C(p, a, c, d, (u16)b, e);
        break;
    }
}
