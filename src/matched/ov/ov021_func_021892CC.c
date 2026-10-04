/*
 * function: func_021892CC
 * address:  0x021892CC
 * packet:   pkt_ov021_021892CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218932C  0x0218932C  thumb
 *   func_02189370  0x02189370  thumb
 *   func_021893C0  0x021893C0  thumb
 *   func_02012844  0x02012844  thumb
 *   func_02162458  0x02162458  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   func_02162438  0x02162438  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09443.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_0218932C(void *a);
extern u32 func_02189370(void *a);
extern void func_021893C0(u8 *p);
struct BigObj;
extern u32 func_02012844(const struct BigObj *p);
extern u32 func_02162458(u8 *p);
extern u8 func_02012984(const struct BigObj *p);
extern void func_02162438(u32 a, u32 b, u32 c);

u32 func_021892CC(u8 *a)
{
    u32 h;

    if (func_0218932C(a) == 1 && func_02189370(a) == 1) {
        func_021893C0(a);
        return 1;
    }
    h = func_02012844((const struct BigObj *)(((struct Obj09443 *)a)->f8));
    if (func_02162458((u8 *)h) == 0) {
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 & ~0x8000;
        func_02162438(h, ((struct Obj09443 *)a)->fD8, func_02012984((const struct BigObj *)(((struct Obj09443 *)a)->f8)));
        *(volatile u16 *)0x04000204 = *(volatile u16 *)0x04000204 | 0x8000;
    }
    return 0;
}
