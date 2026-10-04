/*
 * function: func_021A232C
 * address:  0x021A232C
 * packet:   pkt_ov021_021A232C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A01FC  0x021A01FC  thumb  ov021
 *   func_021A01D4  0x021A01D4  thumb  ov021
 *   func_021A2CC8  0x021A2CC8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00954.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021A01FC(u8 *p, u32 a, u32 b, u32 c);
extern u8 func_021A01D4(u8 *p);
extern void func_021A2CC8(void *p, int a, int b, int c);

void func_021A232C(u8 *p, int a, int b, int c, int d)
{
    int h;

    if (d == 1) {
        func_021A01FC((u8 *)(((struct Obj00954 *)p)->f4), b, a, c);
        return;
    }
    if (d == 2) {
        if (a == func_021A01D4((u8 *)(((struct Obj00954 *)p)->f4))) {
            func_021A01FC((u8 *)(((struct Obj00954 *)p)->f4), b, a, c);
            return;
        }
        h = c / 2;
        func_021A01FC((u8 *)(((struct Obj00954 *)p)->f4), 0x7FDF, func_021A01D4((u8 *)(((struct Obj00954 *)p)->f4)), h);
        func_021A2CC8(p, a, b, h);
    }
}
