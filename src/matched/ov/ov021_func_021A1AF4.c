/*
 * function: func_021A1AF4
 * address:  0x021A1AF4
 * packet:   pkt_ov021_021A1AF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DDE6C     0x021DDE6C  data  ov021  a4
 *   func_021A1BDC  0x021A1BDC  thumb  ov021
 *   func_021A1E08  0x021A1E08  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09548.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void (*const d_021DDE6C[])(void *p, int x);
extern void func_021A1BDC(void *p, u32 v);
extern void func_021A1E08(u32 v, int x);

void func_021A1AF4(u8 *p, int x)
{
    int i;
    u16 t;

    d_021DDE6C[*(u16 *)(p + 8)](p, x);
    if (((struct Obj09548 *)p)->fA == 0) {
        t = ((struct Obj09548 *)p)->f14;
        if (t != 0xFFFF) {
            func_021A1BDC(p, t);
            ((struct Obj09548 *)p)->f14 = 0xFFFF;
        }
    }
    for (i = 0; i < 2; i++) {
        func_021A1E08(*(u32 *)(p + 0x20 + i * 4), x);
    }
}
