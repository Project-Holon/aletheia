/*
 * function: func_021B9824
 * address:  0x021B9824
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD62C  0x021BD62C  thumb  ov217
 *   func_021BD708  0x021BD708  thumb  ov217
 *   func_021BD710  0x021BD710  thumb  ov217
 *
 * Mode query against the +0x18 body: 3 when the body is inert, else 4
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

extern void func_021BD62C(unsigned char *p);
extern u32 func_021BD708(void *p);
extern u32 func_021BD710(void *p);
u32 func_021B9824(u32 a0)
{
    func_021BD62C((unsigned char *)(((struct Obj02554 *)(((u8*)a0)))->f18));
    if (func_021BD708((void *)(((struct Obj02554 *)(((u8*)a0)))->f18)) != 0) {
    if (func_021BD710((void *)(((struct Obj02554 *)(((u8*)a0)))->f18)) == 0) {
    return 1;
    }
    return 4;
    }
    return 3;
}
