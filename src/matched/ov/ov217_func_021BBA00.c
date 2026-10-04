/*
 * function: func_021BBA00
 * address:  0x021BBA00
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021BBD14  0x021BBD14  thumb  ov217
 *   func_021BBD18  0x021BBD18  thumb  ov217
 *   func_021BBD28  0x021BBD28  thumb  ov217
 *   func_021BC580  0x021BC580  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02928.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_020061E4(u32 a);
extern void func_021BBD14(void *p, u32 v);
extern void func_021BBD18(int a, int b);
extern void func_021BBD28(int a, int b);
extern u32 func_021BC580();
u32 func_021BBA00(u32 a0, u32 a1)
{
    func_021BBD28(a0, ((struct Obj02928 *)(((u8*)a0)))->f2C);
    func_021BBD14((void *)a0, a1);
    func_021BBD18(a0, ((struct Obj02928 *)(((u8*)a0)))->f2C);
    func_020061E4(1352);
    return func_021BC580(a0, 4);
}

