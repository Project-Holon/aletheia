/*
 * function: func_021A6AA0
 * address:  0x021A6AA0
 * packet:   pkt_ov021_021A6AA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A66F8  0x021A66F8  thumb  ov021
 *   func_021A678C  0x021A678C  thumb  ov021
 *   func_021A6B9C  0x021A6B9C  thumb  ov021
 *   func_021A6C4C  0x021A6C4C  thumb  ov021
 *   func_021A6C64  0x021A6C64  thumb  ov021
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07501.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021A66F8(u8 *p, u32 m);
extern void func_021A678C(void *a);
extern void func_021A6B9C(u8 *p);
extern u32 func_021A6C4C(u8 *p, u32 v);
extern u32 func_021A6C64(u8 *p);
extern void func_0216D548(u32 *p, u32 v);
extern void func_0216D550(u32 *p, u32 v);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *o, u32 v);
extern void func_021A3964(u8 *o, u32 v);

u32 func_021A6AA0(u8 *p, u32 a1)
{
    u32 r5;

    if (!func_021A66F8(p, 0x40)) {
        func_021A678C(p);
        func_021A6B9C(p + 0xC);
    }
    r5 = (u16)func_021A6C4C(p + 0xC, a1);
    if (func_021A6C64(p + 0xC)) {
        func_0216D548(((struct Obj07501 *)p)->f1C, 0x18);
        func_0216D410(((struct Obj07501 *)p)->f1C, func_02197E7C(r5, 8));
        func_021A3964(*(u8 * *)&((struct Obj07501 *)p)->f14, 1);
        r5 = 9;
    } else {
        func_0216D550(((struct Obj07501 *)p)->f1C, 0x18);
    }
    return r5;
}
