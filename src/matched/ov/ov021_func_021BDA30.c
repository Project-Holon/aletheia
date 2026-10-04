/*
 * function: func_021BDA30
 * address:  0x021BDA30
 * packet:   pkt_ov021_021BDA30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BDBF8  0x021BDBF8  thumb  ov021
 *   func_021BDC2C  0x021BDC2C  thumb  ov021
 *   func_021BDC80  0x021BDC80  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj20137.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021BDBF8(u32 a);
extern void func_021BDC2C(u32 *, u32);
extern void func_021BDC80(u32 *);

u32 func_021BDA30(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];

    switch (*st) {
    case 0:
        if (((struct Obj20137 *)p)->f48 != 0)
            func_021BDBF8((u32)ctx);
        func_021BDC2C(ctx, a);
        (*st)++;
        break;
    case 1:
        func_021BDC80(ctx);
        return 1;
    }
    return 0;
}
