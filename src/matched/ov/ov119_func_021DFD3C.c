/*
 * function: func_021DFD3C
 * address:  0x021DFD3C
 * packet:   pkt_ov119_021DFD3C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02005E9C  0x02005E9C  thumb
 *   func_02005DE4  0x02005DE4  thumb
 *   func_02005DF8  0x02005DF8  thumb
 *
 * Decrement the +0x11f8 guard byte (both its condition and the store use
 * that same pool word) and pulse the 0x3c delay. Non-SDK dep of
 * func_021DFDA0's case-5/6 arms.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00906.h"

typedef unsigned char u8;

extern void func_02005E9C(void);
typedef unsigned int   u32;
extern void func_02005DE4(void *p);
extern void func_02005DF8(u32 a);

void func_021DFD3C(void *p)
{
    u8 *b = p;

    if (((struct Obj00906 *)b)->f11F8 != 0) {
        func_02005E9C();
        ((struct Obj00906 *)b)->f11F8 -= 1;
        func_02005DE4(0);
        func_02005DF8(0x3c);
    }
}
