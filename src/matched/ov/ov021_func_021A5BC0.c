/*
 * function: func_021A5BC0
 * address:  0x021A5BC0
 * packet:   pkt_ov021_021A5BC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A5EA0  0x021A5EA0  thumb  ov021
 *   func_021A5EA4  0x021A5EA4  thumb  ov021
 *   func_021A5EDC  0x021A5EDC  thumb  ov021
 *   func_021A5F14  0x021A5F14  thumb  ov021
 *   func_021A5F38  0x021A5F38  thumb  ov021
 *   func_021A5F74  0x021A5F74  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01119.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void func_021A5EA0(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern void func_021A5EA4(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern void func_021A5EDC(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern void func_021A5F14(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern void func_021A5F38(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);
extern void func_021A5F74(u8 *p, void *a, u32 b, u32 c, u32 d, u32 e);

void func_021A5BC0(u8 *p, u32 k, u32 b, u32 c, u32 d, u32 e)
{
    void *a = ((struct Obj01119 *)p)->f1C;

    switch (k) {
    case 0:
        func_021A5EA0(p, a, b, c, d, e);
        break;
    case 1:
        func_021A5EA4(p, a, b, c, d, e);
        break;
    case 2:
        func_021A5EDC(p, a, b, c, d, e);
        break;
    case 3:
        func_021A5F14(p, a, b, c, d, e);
        break;
    case 4:
        func_021A5F38(p, a, b, c, d, e);
        break;
    case 5:
        func_021A5F74(p, a, b, c, d, e);
        break;
    }
}
