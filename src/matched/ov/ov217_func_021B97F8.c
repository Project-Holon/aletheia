/*
 * function: func_021B97F8
 * address:  0x021B97F8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BABC4  0x021BABC4  thumb  ov217
 *   func_021BAC90  0x021BAC90  thumb  ov217
 *   func_021BAC98  0x021BAC98  thumb  ov217
 *
 * Mode query against the +0x14 body: 2 when the body is inert, else 4
 * when it is still busy, else 1.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02554.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_021BABC4(void *self);
extern u32 func_021BAC90(void *p);
extern u32 func_021BAC98(void *p);
u32 func_021B97F8(u32 a0)
{
    func_021BABC4((void *)(((struct Obj02554 *)(((u8*)a0)))->f14));
    if (func_021BAC90((void *)(((struct Obj02554 *)(((u8*)a0)))->f14)) != 0) {
    if (func_021BAC98((void *)(((struct Obj02554 *)(((u8*)a0)))->f14)) == 0) {
    return 1;
    }
    return 4;
    }
    return 2;
}
